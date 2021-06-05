#pragma once
#include"Mission.h"
#include "PRovers.h"

PRover::PRover(int spd, int Checkupdur, int Ncheckup, int Mcomp, Mission* roverMission) : Rovers(spd, Checkupdur, Ncheckup, Mcomp)
{
	RoverMission = roverMission;

}

void PRover::setRoverMission(Mission a)
{
	RoverMission = &a;
}

Mission* PRover:: getRoverMission()
{
	return RoverMission;
}

bool PRover::isAssigned() //is rover is Assigend to a mission or no and this function is made for potential use in future 
{
	if (this->RoverMission)
	{
		RoverMission->setAssigned(true);
		return true;
	}
	else
	{
		RoverMission->setAssigned(false);
		return false;
	}
}
