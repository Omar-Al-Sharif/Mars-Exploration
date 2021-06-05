#include"ERovers.h"
#include"Mission.h"

ERover:: ERover(int spd, int Checkupdur, int Ncheckup, int Mcomp, Mission* roverMission) : Rovers(spd, Checkupdur, Ncheckup, Mcomp)
{
	roverMission = nullptr;
}


void ERover::setRoverMission(Mission a)
{
	RoverMission = &a;
}

Mission* ERover::getRoverMission()
{
	return RoverMission;
}

bool ERover::isAssigned() //is rover is Assigend to a mission or no and this function is made for potential use in future 
{
	if (this->RoverMission)
		return true;
	else return false;
}
