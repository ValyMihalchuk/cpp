#pragma once
#include "SetUpAndLibs.h"

enum bounties {
	DEFAULT,    
	ENERGY,
	FRUIT,
	NONE
};
class Element {
private:
	bool empty;
	bounties bounty;
	xy point;
public:
	Element(bool Empty, const bounties& Bounty, const xy& Point) { empty = Empty; bounty = Bounty; point = Point; }
	bool IsEmpty() const {return empty;}
	bounties GetBounty() const {return bounty;}
	void SetBounty(bounties bounty) {bounty = bounty;}
	xy GetPoint() const {return point;}
};


