#include "../Data structure and algorithm/Rovers.h"


Rovers::Rovers(int spd, int Checkupdur, int Ncheckup, int Mcomp)
{
	speed = spd;
	checkUpDur = Checkupdur;
	NeedCheckUP = Ncheckup;
	MissionComp = Mcomp;
}
void Rovers::setRoverMission(Mission a)
{
	RoverMission = &a;
}


Mission* Rovers::getRoverMission()
{
	return RoverMission;
}

void Rovers::setSpeed(int a)
{
	speed = a;
}


int Rovers::getSpeed()
{
	return speed;
}

void Rovers::setCheckUpDur(int a)
{
	checkUpDur = a;
}

int Rovers::getCheckUpDur()
{
	return checkUpDur;
}


int Rovers::getMissionComp()
{
	return MissionComp;
}

void Rovers::setMissionComp(int a)
{
	MissionComp = a;
}

void Rovers::setNeedCheckUp(int a)
{
	NeedCheckUP = a;
}

int Rovers::getNeedCheckUp()
{
	return NeedCheckUP;
}

