#include "TurnEvents.hh"

namespace WH40k {

EventBase::Topic TurnStartEvent::getTopic()
{
    return "TurnEvent";
}

EventBase::Topic TurnEndEvent::getTopic()
{
    return "TurnEvent";
}

EventBase::Topic PhaseStartEvent::getTopic()
{
    return "TurnEvent";
}

EventBase::Topic PhaseEndEvent::getTopic()
{
    return "TurnEvent";
}

}

