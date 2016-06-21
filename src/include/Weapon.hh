
#ifndef WH40K_WEAPON_HH__
#define WH40K_WEAPON_HH__

namespace WH40k {

class Weapon {
public:
  enum Type {Melee, RapidFire, Assault, Bomb, Heavy, Ordnance, Pistol, PrimaryWeapon, Salvo};
	virtual Type getType()=0;
	virtual int getRange()=0; //can be template shaped
    virtual int getStrength()=0; //can be based off user strength
	virtual int getArmourPiercingValue()=0;
	virtual int getNumShots()=0;
};

};

#endif

