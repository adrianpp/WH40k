/*
Turn sequence:

1) start of turn
2) movement phase
  a) move each model
  b) restrictions: models cannot move through other units or within 1" (without charging); cannot move if in close combat; unit must stay coherent
3) psychic phase
  a) generate warp charge (number of available dice): d6 + total mastery levels
  b) manifest psychic powers (costs warp charge, generally requires psychic test)
    i) select psyker and psychic power
		ii) declare target
		iii) take psychic test
		iv) deny the witch
		v) resolve pyschic power
4) shooting phase
  a) nominate unit to shoot
	b) choose target
	c) select weapon
	d) roll to hit
	  d6 >= 7-(BS) [for BS<7]
		d6 >= 2; reroll granted with d6 >= 12-(BS) [for BS>=7]
	e) roll to wound (always 2+ at minimum)
		d6 >= 4 + targetToughness - weaponStrength [for targetToughness - weaponStrength < 3]
		d6 >= 6 [for targetToughness - weaponStrength == 3]
		can't wound [for targetToughness - weaponStrength > 3]
	f) allocate wounds, take saves, and remove casualties
	g) select another weapon
5) assault phase
  a) charge:
	  i) declare charge
		ii) resolve overwatch
		iii) roll charge range
		iv) charge move
		v) declare next charge
	b) fight
	  i) choose combat
		ii) fight close combat
		iii) determine assualt results
		iv) choose next combat
6) end of turn

each phase sends events that can be acted on by models, for example by adding or removing options from a context menu
*/
#ifndef _WH40K_GAMEENGINE_H__
#define _WH40K_GAMEENGINE_H__

#include "Event.hh"

namespace WH40k {

class GameEngine {
public:
    GameEngine(EventRouter& router);
    void gameLoop();
private:
    EventRouter& router;
    int turnNumber;
};

}

#endif

