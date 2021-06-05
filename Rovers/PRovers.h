#pragma once
#include <iostream>
#include "Rovers.h"
#include"../Data structure and algorithm/Mission.h"


class PRover : public Rovers
{
private :
	Mission* RoverMission;

public :
	PRover(int spd, int Checkupdur, int Ncheckup, int Mcomp, Mission* roverMission);
	void setRoverMission(Mission a);
	Mission* getRoverMission();
	bool isAssigned();
};
