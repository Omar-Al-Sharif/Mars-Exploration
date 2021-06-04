#include "Mission.h"

Mission::Mission(int fd, int md, int targetloc, int significance,int Id)
{
	FD = fd;
	MD = md;
	targetlocation = targetloc;
	Significance = significance;
	missionID = Id;
}

void Mission::setWaitingDays(int wd)
{
	WD = wd;
}

void Mission::assigntoRover(Rovers* R)
{
	this->R = R;
	int speed = R->getSpeed();
	ED = 2 * (targetlocation * speed) / 25 + MD;
	CD = WD + ED;  //Completion day is the summation of waiting days + execution days 
	// Because execution day aleady includes the mission duration 
}

int Mission::getFinishDay() const
{
	return CD;
}
