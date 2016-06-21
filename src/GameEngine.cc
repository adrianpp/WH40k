#include <iostream>
#include "GameEngine.hh"
#include "TurnEvents.hh"

namespace WH40k {

GameEngine::GameEngine(EventRouter& router) : router(router), turnNumber(0)
{
}

void GameEngine::addModel(std::shared_ptr<Model> model)
{
    model_list.push_back(model);
}

bool GameEngine::startTurn()
{
    router.publishEvent(new TurnStartEvent());
    return true;
}

bool GameEngine::gotoMovementPhase()
{
    router.publishEvent(new MovementPhaseStartEvent());
    //do the movement phase
    for(std::vector<std::shared_ptr<Model>>::iterator MI = model_list.begin(); MI != model_list.end(); ++MI)
    {
        //move the model
        int movement = -1;
        while( !(0 <= movement and movement <= (*MI)->getMovement()) ) {
            std::cout << "How much to move model " << *MI << "(movement speed " << (*MI)->getMovement() << "): ";
            std::cin >> movement;
        }
    }
    return true;
}

bool GameEngine::gotoPsychicPhase()
{
    router.publishEvent(new MovementPhaseEndEvent());
    //check if that succeeded?
    router.publishEvent(new PsychicPhaseStartEvent());
    //do the psychic phase
    return true;
}

bool GameEngine::gotoShootingPhase()
{
    router.publishEvent(new PsychicPhaseEndEvent());
    //check if that succeeded?
    router.publishEvent(new ShootingPhaseStartEvent());
    //do the shooting phase
    return true;
}

bool GameEngine::gotoAssaultPhase()
{
    router.publishEvent(new ShootingPhaseEndEvent());
    //check if that succeeded?
    router.publishEvent(new AssaultPhaseStartEvent());
    //do the assault phase
    return true;
}

bool GameEngine::endTurn()
{
    router.publishEvent(new AssaultPhaseEndEvent());
    //check if that succeeded?
    router.publishEvent(new TurnEndEvent());
    return true;
}

}

