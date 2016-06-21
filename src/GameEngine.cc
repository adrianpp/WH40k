#include "GameEngine.hh"
#include "TurnEvents.hh"

namespace WH40k {

GameEngine::GameEngine(EventRouter& router) : router(router), turnNumber(0)
{
}

void GameEngine::gameLoop()
{
    router.publishEvent(new TurnStartEvent());
    router.publishEvent(new MovementPhaseStartEvent());
    router.publishEvent(new PsychicPhaseStartEvent());
    router.publishEvent(new ShootingPhaseStartEvent());
    router.publishEvent(new AssaultPhaseStartEvent());
    router.publishEvent(new TurnEndEvent());
}

}

