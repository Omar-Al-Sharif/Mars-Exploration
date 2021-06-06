#pragma once
#include "Mission.h"

Mission::Mission(int fd, int md, int targetloc, int significance, int Id)
{
	FD = fd;
	MD = md;
	targetlocation = targetloc;
	Significance = significance;
	numberOfmissions++;
	missionID = Id;
	Assigned = false;
}

Mission::Mission(int fd, int md, int targetloc, int Id)
{
	FD = fd;
	MD = md;
	targetlocation = targetloc;
	numberOfmissions++;
	missionID = Id;
	Assigned = false;
}



/////////////////////////////////////////////////////////////

int Mission::numberOfmissions = 0; // static data member initialization

//////////////////////////////////////////////////////////
Mission::Mission()
{

}

void Mission::setAssigned(bool t)
{
	Assigned = t;
}

bool Mission::getAssigned()
{
	return Assigned;
}

void Mission::setWaitingDays()
{
	WD = EWD-SWD;
}


//void Mission::assigntoRover(Rovers* R)
//{
//	this->R = R;
//	int speed = R->getSpeed();
//	ED = 2 * (targetlocation * speed) / 25 + MD;
//	CD = WD + ED;  //Completion day is the summation of waiting days + execution days 
//	// Because execution day aleady includes the mission duration 
//}

void Mission::setSWD(int x)
{
	SWD = x;
}


void Mission::setEWD(int y)
{
	EWD = y;
}

int Mission::getEWD()
{
	return EWD;
}

int Mission::getSWD()
{
	return SWD;
}

int Mission::getFinishDay() const
{
	return CD;
}

int Mission::getFormulationDay() const
{
	return FD;
}
int Mission::getMissionId() const
{
	return missionID;
}
int Mission::getWaitingDays() const
{
	return WD;
}
int Mission::getExecutionDays() const
{
	return ED;
}
