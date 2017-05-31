#ifndef _WH40K_QUERYEVENT_H__
#define _WH40K_QUERYEVENT_H__

#include "Event.hh"
#include "Model.hh"

namespace WH40k {

class QueryAttribute : public EventBase {
public:
	virtual Topic getTopic();
    virtual std::string attributeName()=0;
    virtual std::shared_ptr<Model> whichModel()=0;
};

class QueryAttributeMovement : public QueryAttribute {
public:
    virtual std::string attributeName();
};

}

#endif

