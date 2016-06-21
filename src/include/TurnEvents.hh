#ifndef _WH40K_TURNEVENTS_H__
#define _WH40K_TURNEVENTS_H__

#include "Event.hh"

namespace WH40k {

class TurnStartEvent : public EventBase {
public:
	virtual Topic getTopic();
};

class TurnEndEvent : public EventBase {
public:
	virtual Topic getTopic();
};

class PhaseStartEvent : public EventBase {
public:
	virtual Topic getTopic();
};

class MovementPhaseStartEvent : public PhaseStartEvent {
};

class PsychicPhaseStartEvent : public PhaseStartEvent {
};

class ShootingPhaseStartEvent : public PhaseStartEvent {
};

class AssaultPhaseStartEvent : public PhaseStartEvent {
};

class PhaseEndEvent : public EventBase {
public:
	virtual Topic getTopic();
};

class MovementPhaseEndEvent : public PhaseEndEvent {
};

class PsychicPhaseEndEvent : public PhaseEndEvent {
};

class ShootingPhaseEndEvent : public PhaseEndEvent {
};

class AssaultPhaseEndEvent : public PhaseEndEvent {
};

}

#endif

