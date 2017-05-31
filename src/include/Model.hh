//Base class for all individual models

//each model represents one instance of a character or vehicle in the game

#ifndef WH40K_MODEL_HH__
#define WH40K_MODEL_HH__

#include <vector>
#include <string>

namespace WH40k {

class Model {
public:
  enum BaseType {NoBase, SmallBase, LargeBase, Vehicle};
  virtual BaseType getBaseRadius()=0; //the base that the model is mounted on
  virtual int getMovement()=0; //the movement of the model
  virtual int getWeaponSkill()=0;
  virtual int getBallisticSkill()=0;
  virtual int getStrength()=0;
  virtual int getToughness()=0;
  virtual int getWounds()=0;
  virtual int getAttacks()=0;
  virtual int getLeadership()=0;
  virtual int getArmourSave()=0;
  virtual std::vector<std::string> getFactionKeywords()=0;
  virtual std::vector<std::string> getKeywords()=0;
};

};

#endif

