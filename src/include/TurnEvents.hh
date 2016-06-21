#ifndef _WH40K_TURNEVENTS_H__
#define _WH40K_TURNEVENTS_H__

#include "Event.hh"

namespace WH40k {

class TurnStartEvent : public EventBase {
};

class TurnEndEvent : public EventBase {
};

class PhaseStartEvent : public EventBase {
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

