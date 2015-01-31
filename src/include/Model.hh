//Base class for all individual models

//each model represents one instance of a character or vehicle in the game

#ifndef WH40K_MODEL_HH__
#define WH40K_MODEL_HH__

namespace WH40k {

enum BaseType {NoBase, SmallBase, LargeBase};

class Model {
public:
  virtual BaseType getBaseRadius()=0; //the base that the model is mounted on
};

};

#endif

