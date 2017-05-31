#include <iostream>

#include "GameEngine.hh"
#include "TurnEvents.hh"
#include "BasicInfantry.hh"
#include "QueryEvents.hh"

using namespace WH40k;

void eventPrinter(std::shared_ptr<EventBase> event)
{
    std::cout << "Event: " << event->getTopic() << std::endl;
}

class TacticalSpaceMarine : public BasicInfantry {
public:
    TacticalSpaceMarine() : BasicInfantry(6, 4, 4, 4, 4, 1, 1, 8, 3) {}
    virtual std::string getFaction() {return "Ultramarines";}
    virtual std::vector<std::string> getFactionKeywords() {
      return {"Imperium", "Adeptus Astartes", getFaction()};
    }
    virtual std::vector<std::string> getKeywords() {
      return {"Infantry"};
    }
};

int main()
{
    EventRouter eventrouter;
    GameEngine gameEngine(eventrouter);
    eventrouter.registerListener(createListenerForEvent<EventBase>(eventPrinter));
    //add the models being played with
    std::shared_ptr<Model> tsm1(new TacticalSpaceMarine);
    gameEngine.addModel(tsm1); 
    gameEngine.addModel(std::shared_ptr<Model>(new TacticalSpaceMarine)); 
    gameEngine.addModel(std::shared_ptr<Model>(new TacticalSpaceMarine)); 
    gameEngine.addModel(std::shared_ptr<Model>(new TacticalSpaceMarine)); 
    gameEngine.addModel(std::shared_ptr<Model>(new TacticalSpaceMarine)); 

    //test querying an attribute
    std::shared_ptr<QueryAttributeMovement> query(new QueryAttributeMovement(tsm1));
    eventrouter.publishEvent(query);
    std::cout << "Movement attribute of tsm1 is : " << query->getCurrentMovement() << std::endl;

    //run the game
    for(int turnNum = 0; turnNum < 6; ++turnNum)
    {
      while(!gameEngine.startTurn()){//try to start the turn
      }
      while(!gameEngine.gotoMovementPhase()){//try to start the movement phase
      }
      while(!gameEngine.gotoPsychicPhase()){//try to start the psychic phase
      }
      while(!gameEngine.gotoShootingPhase()){//try to start the shooting phase
      }
      while(!gameEngine.gotoAssaultPhase()){//try to start the assault phase
      }
      while(!gameEngine.endTurn()){//try to end the turn
      }
    }
    return 0;
}
