#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <memory>
#include <map>

class NumberSource {
public:
    virtual int getValue()=0;
};

class Constant : public NumberSource {
public:
    Constant(int v) : _v(v) {}
    virtual int getValue(){return _v;}
private:
    int _v;
};

class Dice : public NumberSource {
public:
    Dice(int n, int s) : _n(n), _s(s) {}
    int getNum() {return _n;}
    int getSize() {return _s;}
    int roll()
    {
        int total = 0;
        for(int i = 0; i < getNum(); ++i)
            total += 1 + std::rand() % getSize();
        return total;
    }
    int rollGreaterEqual(int value)
    {
        int total = 0;
        for(int i = 0; i < getNum(); ++i)
        {
            int roll = 1 + std::rand() % getSize();
            if( roll >= value )
                ++total;
        }
        return total;
    }
    virtual int getValue(){return roll();}
private:
    int _n, _s;
};

class Attribute {
public:
    Attribute(std::string name) : _name(name) {}
    std::string getName(){return _name;}
    bool operator == (Attribute rhs){return rhs.getName() == getName();}
public:
    std::string _name;
};

class Weapon {
public:
    Weapon(std::string name, std::shared_ptr<NumberSource> s, std::shared_ptr<NumberSource> ap, std::shared_ptr<NumberSource> n, std::shared_ptr<NumberSource> d) : _name(name), _s(s), _ap(ap), _n(n), _d(d) {}
    std::string getName(){return _name;}
    int getStrength(){return _s->getValue();}
	int getArmourPiercingValue(){return _ap->getValue();}
    int getNumShots(){return _n->getValue();}
    int getDamage(){return _d->getValue();}
    Weapon& attr(Attribute a){attrs.push_back(a); return *this;}
    bool hasAttr(Attribute a){
        for(auto AI = attrs.begin(); AI != attrs.end(); ++AI)
            if( a == *AI ) return true;
        return false;
    }
    std::vector<Attribute>& attr(){return attrs;}
    int& property(std::string s) {return propMap[s];}
private:
    std::string _name;
    std::shared_ptr<NumberSource> _s, _ap, _n, _d;
    std::vector<Attribute> attrs;
    std::map<std::string, int> propMap;
};

class Model {
public:
    Model(std::string name, int m, int ws, int bs, int s, int t, int w, int a, int ld, int as, std::vector<Weapon> weapons) : _name(name), _m(m), _ws(ws), _bs(bs), _s(s), _t(t), _w(w), _a(a), _ld(ld), _as(as), _weapons(weapons) {}
    std::string getName() {return _name;}
    virtual int getMovement(){return _m;}
    virtual int getWeaponSkill(){return _ws;}
    virtual int getBallisticSkill(){return _bs;}
    virtual int getStrength(){return _s;}
    int getToughness(){return _t;}
    int getWounds(){return _w;}
    virtual int getAttacks(){return _a;}
    int getLeadership(){return _ld;}
    int getArmourSave(){return _as;}
    std::vector<Weapon>& getWeapons(){return _weapons;}
private:
   std::string _name;
   int _m, _ws, _bs, _s, _t, _w, _a, _ld, _as;
   std::vector<Weapon> _weapons;
};

int getWoundsSuffered(Model shooter, Weapon w, Model shootee)
{
    //roll to hit - number of shots of weapon, rolling over shooter ballistic skill
    int numShots = w.getNumShots();
    int numHits = Dice(numShots, 6).rollGreaterEqual(shooter.getBallisticSkill());
    if( w.hasAttr(Attribute("autohit")) ) numHits = numShots;
    w.property("num_hits") = numHits;
    //roll to wound
    int woundOn = -1;
    if( w.getStrength() * 2 <= shootee.getToughness() ) 
        woundOn = 6; //wound on 5+
    else if(w.getStrength() < shootee.getToughness() )
        woundOn = 5;
    else if(w.getStrength() == shootee.getToughness() )
        woundOn = 4;
    else if(w.getStrength() >= 2 * shootee.getToughness() )
        woundOn = 2;
    else if(w.getStrength() > shootee.getToughness() )
        woundOn = 3;
    int numWounds = Dice(numHits,6).rollGreaterEqual(woundOn);
    //roll saves
    int numSaved = Dice(numWounds,6).rollGreaterEqual(shootee.getArmourSave() - w.getArmourPiercingValue());
    //calculate wounds suffered
    int woundsSuffered = 0;
    for(int c = 0; c < numWounds - numSaved; ++c)
    {
        int roll = w.getDamage();
        //a model can't suffer more wounds than it has
        if( roll > shootee.getWounds() ) roll = shootee.getWounds();
        woundsSuffered += roll;
    }
    return woundsSuffered;
}

template<int i>
class C : public std::shared_ptr<NumberSource> {
public:
    C() : std::shared_ptr<NumberSource>(new Constant(i)) {}
};

template<int N, int S>
class D : public std::shared_ptr<NumberSource> {
public:
    D() : std::shared_ptr<NumberSource>(new Dice(N,S)) {}
};

template<class F>
class FunctionalNumberSource : public NumberSource {
public:
    FunctionalNumberSource(F f) : _f(f) {}
    virtual int getValue() {return _f();}
private:
    F _f;
};

template<class F>
std::shared_ptr<NumberSource> functionalSource(F f)
{
    return std::shared_ptr<NumberSource>(new FunctionalNumberSource<F>(f));
}

int main()
{
    std::srand(time(NULL));
    Model *shooter, *target;
    //list of common used number sources
    std::shared_ptr<NumberSource> C0{C<0>()}, C1{C<1>()}, D3{D<1,3>()}, D6{D<1,6>()};
    //list of weapons
    Weapon bolter("bolter", C<4>(), C0, C1, C1);
    Weapon grav_gun("gravGun", C<5>(), C<-3>(), C1, functionalSource([&target](){if(target->getArmourSave()<=3) return Dice(1,3).roll(); return 1;}));
    Weapon gravcannon("gravCannon", C<5>(), C<-3>(), C<4>(), functionalSource([&target](){if(target->getArmourSave()<=3) return Dice(1,3).roll(); return 1;}));
    Weapon lascannon("lascannon", C<9>(), C<-3>(), C1, D6);
    Weapon acid_spray("acidSpray", functionalSource([&shooter](){return shooter->getStrength();}), C<-1>(), D6, D3);
    acid_spray.attr(Attribute("autohit"));
    Weapon fleshborer_hive("fleshborerHive", C<5>(), C0, C<20>(), C1);
    Weapon stinger_salvo("stingerSalvo", C<5>(), C<-1>(), C<4>(), C1);
    Weapon rupture_cannon("ruptureCannon", C<10>(), functionalSource([&rupture_cannon](){if(rupture_cannon.property("num_hits") == 2) return -4; return -1;}), C<2>(), functionalSource([&rupture_cannon](){if(rupture_cannon.property("num_hits") == 2) return Dice(1,6).roll(); return 2;}));
    Weapon fleshborer("fleshborer", C<4>(), C0, C1, C1);
    Weapon devourer("devourer", C<4>(), C0, C<3>(), C1);
    Weapon deathspitter("deathspitter", C<5>(), C<-1>(), C<3>(), C1);
    //list of models
    std::vector<Model> allModels = {
            Model("SpaceMarine", 6, 3, 3, 4, 4, 1, 1, 8, 3, {bolter, grav_gun, gravcannon, lascannon}),
            Model("Terminator", 5, 3, 3, 4, 4, 2, 2, 8, 2, {}),
            Model("Rhino", 12, 6, 3, 6, 7, 10, 3, 8, 3, {}),
            Model("LandRaider", 10, 6, 3, 8, 8, 16, 6, 9, 2, {}),
            Model("KnightErrant", 12, 3, 3, 8, 8, 24, 4, 9, 3, {}),
            Model("Termagant", 6, 4, 4, 3, 3, 1, 1, 5, 6, {fleshborer, devourer}),
            Model("TyranidWarrior", 6, 3, 4, 4, 4, 3, 3, 9, 4, {devourer, deathspitter}),
            Model("Carnifex", 7, 4, 4, 6, 7, 8, 4, 6, 3, {}),
            Model("Tyrannofex", 6, 4, 4, 7, 8, 14, 4, 7, 3, {acid_spray, fleshborer_hive, stinger_salvo, rupture_cannon})
        };

    for(int m1 = 0; m1 < allModels.size(); ++m1)
        for(auto W = allModels[m1].getWeapons().begin(); W != allModels[m1].getWeapons().end(); ++W)
            for(int m2 = 0; m2 < allModels.size(); ++m2)
            {
                shooter = &allModels[m1];
                target = &allModels[m2];
                int iters = 10000;
                int woundsSuffered = 0;
                for(int i = 0; i < iters; ++i)
                    woundsSuffered += getWoundsSuffered(allModels[m1], *W, allModels[m2]);
                std::cout << allModels[m1].getName() << "." << W->getName() << " -> " << allModels[m2].getName() << " : " << float(woundsSuffered)/iters << std::endl;
            }

    return 0;
}
