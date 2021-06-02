#pragma once
#include"Mission.h"
#include "PRovers.h"


void PRover::setRoverMission(Mission a)
{
	Pmission = &a;
}

Mission* PRover:: getRoverMission()
{
	return Pmission;
}
