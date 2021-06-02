#include"ERovers.h"
#include"Mission.h"


void ERover::setRoverMission(Mission a)
{
	Emission = &a;
}

Mission* ERover::getRoverMission()
{
	return Emission;
}
