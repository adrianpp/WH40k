#include <iostream>

#include "GameEngine.hh"
#include "TurnEvents.hh"
#include "Infantry.hh"

using namespace WH40k;

void eventPrinter(std::shared_ptr<EventBase> event)
{
    std::cout << "Event: " << event->getTopic() << std::endl;
}

class TacticalSpaceMarine : public InfantryBasic {
public:
    TacticalSpaceMarine() : InfantryBasic(4, 4, 4, 4, 1, 4, 1, 8, 3) {}
};

int main()
{
    EventRouter eventrouter;
    GameEngine gameEngine(eventrouter);
    eventrouter.registerListener(createListenerForEvent<EventBase>(eventPrinter));
    //add the models being played with
    gameEngine.addModel(std::shared_ptr<Model>(new TacticalSpaceMarine)); 
    gameEngine.addModel(std::shared_ptr<Model>(new TacticalSpaceMarine)); 
    gameEngine.addModel(std::shared_ptr<Model>(new TacticalSpaceMarine)); 
    gameEngine.addModel(std::shared_ptr<Model>(new TacticalSpaceMarine)); 
    gameEngine.addModel(std::shared_ptr<Model>(new TacticalSpaceMarine)); 
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
