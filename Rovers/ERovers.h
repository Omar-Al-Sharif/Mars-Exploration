#pragma once
#include <iostream>
#include "Rovers.h"
#include"Emission.h"


class ERover : public Rovers
{
private:
	Mission* RoverMission;


public:
	ERover(int spd, int Checkupdur, int Ncheckup, int Mcomp, Mission* roverMission);
	void setRoverMission(Mission a);
	Mission* getRoverMission();
	bool isAssigned();

};
