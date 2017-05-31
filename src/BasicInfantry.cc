#include "BasicInfantry.hh"

namespace WH40k {

BasicInfantry::BasicInfantry(int m, int ws, int bs, int s, int t, int w, int a, int ld, int as, Model::BaseType baseType) : _m(m), _ws(ws), _bs(bs), _s(s), _t(t), _w(w), _a(a), _ld(ld), _as(as), _baseType(baseType)
{
}

int BasicInfantry::getMovement() {return _m;}
int BasicInfantry::getWeaponSkill() {return _ws;}
int BasicInfantry::getBallisticSkill(){return _bs;}
int BasicInfantry::getStrength(){return _s;}
int BasicInfantry::getToughness(){return _t;}
int BasicInfantry::getWounds(){return _w;}
int BasicInfantry::getAttacks(){return _a;}
int BasicInfantry::getLeadership(){return _ld;}
int BasicInfantry::getArmourSave(){return _as;}
Model::BaseType BasicInfantry::getBaseRadius(){return _baseType;}


};

