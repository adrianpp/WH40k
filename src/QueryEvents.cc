#include "QueryEvents.hh"

namespace WH40k {

EventBase::Topic QueryAttribute::getTopic()
{
    return "QueryAttribute::" + attributeName();
}

std::string QueryAttributeMovement::attributeName()
{
    return "Movement";
}

}

