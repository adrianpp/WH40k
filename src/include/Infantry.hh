
#ifndef WH40K_INFANTRY_HH__
#define WH40K_INFANTRY_HH__

#include "Model.hh"

namespace WH40k {

class Infantry : public Model {
public:
	virtual int getWeaponSkill()=0;
	virtual int getBallisticSkill()=0;
	virtual int getStrength()=0;
	virtual int getToughness()=0;
	virtual int getWounds()=0;
	virtual int getInitiative()=0;
	virtual int getAttacks()=0;
	virtual int getLeadership()=0;
	virtual int getArmourSave()=0;
};

class InfantryBasic : public Infantry {
public:
  InfantryBasic(int ws, int bs, int s, int t, int w, int i, int a, int ld, int as, Model::BaseType baseType=Model::SmallBase);
 	virtual int getWeaponSkill();
	virtual int getBallisticSkill();
	virtual int getStrength();
	virtual int getToughness();
	virtual int getWounds();
	virtual int getInitiative();
	virtual int getAttacks();
	virtual int getLeadership();
	virtual int getArmourSave();
  virtual Model::BaseType getBaseRadius();
private:
   int _ws, _bs, _s, _t, _w, _i, _a, _ld, _as;
	 Model::BaseType _baseType;
};

};

#endif

