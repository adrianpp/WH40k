#include "QueryEvents.hh"

namespace WH40k {

EventBase::Topic QueryAttribute::getTopic()
{
    return "QueryAttribute::" + attributeName();
}

QueryAttributeMovement::QueryAttributeMovement(std::shared_ptr<Model> m) : model(m), current_movement(0)
{
    if( m != nullptr ) current_movement = model->getMovement();
}
std::string QueryAttributeMovement::attributeName()
{
    return "Movement";
}
std::shared_ptr<Model> QueryAttributeMovement::whichModel()
{
    return model;
}
int& QueryAttributeMovement::getCurrentMovement()
{
    return current_movement;
}


}

