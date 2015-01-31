#include "Infantry.hh"

namespace WH40k {

InfantryBasic::InfantryBasic(int ws, int bs, int s, int t, int w, int i, int a, int ld, int as, Model::BaseType baseType) : _ws(ws), _bs(bs), _s(s), _t(t), _w(w), _i(i), _a(a), _ld(ld), _as(as), _baseType(baseType)
{
}

int InfantryBasic::getWeaponSkill() {return _ws;}
int InfantryBasic::getBallisticSkill(){return _bs;}
int InfantryBasic::getStrength(){return _s;}
int InfantryBasic::getToughness(){return _t;}
int InfantryBasic::getWounds(){return _w;}
int InfantryBasic::getInitiative(){return _i;}
int InfantryBasic::getAttacks(){return _a;}
int InfantryBasic::getLeadership(){return _ld;}
int InfantryBasic::getArmourSave(){return _as;}
Model::BaseType InfantryBasic::getBaseRadius(){return _baseType;}


};

