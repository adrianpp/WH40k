#include "TurnEvents.hh"

namespace WH40k {

EventBase::Topic TurnStartEvent::getTopic()
{
    return "TurnEvent::Start";
}

EventBase::Topic TurnEndEvent::getTopic()
{
    return "TurnEvent::End";
}

EventBase::Topic PhaseStartEvent::getTopic()
{
    return "TurnEvent::Phase::Start";
}

EventBase::Topic PhaseEndEvent::getTopic()
{
    return "TurnEvent::Phase::End";
}

}

