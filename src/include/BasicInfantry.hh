
#ifndef WH40K_INFANTRY_HH__
#define WH40K_INFANTRY_HH__

#include "Model.hh"

namespace WH40k {

class BasicInfantry : public Model {
public:
    BasicInfantry(int m, int ws, int bs, int s, int t, int w, int a, int ld, int as, Model::BaseType baseType=Model::SmallBase);
    virtual int getMovement();
    virtual int getWeaponSkill();
    virtual int getBallisticSkill();
    virtual int getStrength();
    virtual int getToughness();
    virtual int getWounds();
    virtual int getAttacks();
    virtual int getLeadership();
    virtual int getArmourSave();
    virtual Model::BaseType getBaseRadius();
private:
   int _m, _ws, _bs, _s, _t, _w, _a, _ld, _as;
	 Model::BaseType _baseType;
};

};

#endif

