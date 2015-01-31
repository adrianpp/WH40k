
#ifndef WH40K_VEHICLE_HH__
#define WH40K_VEHICLE_HH__

#include "Model.hh"

namespace WH40k {

class Vehicle : public Model {
public:
	enum Type {Chariot, Fast, Flyer, Heavy, Hovor, OpenTopped, Skimmer, Tank, Transport, Walker, SuperHeavyVehicle, SuperHeavyWalker, SuperHeavyFlyer};
	virtual Type getTypes()=0; //fixme: allow multiple types
  virtual int getBallisticSkill()=0;
	virtual int getFrontArmour()=0;
	virtual int getSideArmour()=0;
	virtual int getRearArmour()=0;
	virtual int getHullPoints()=0;
	//fixme: walkers also have weapon skill, strength, initiative, and attacks
};

};

#endif

