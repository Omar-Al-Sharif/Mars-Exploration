#pragma once
#include <iostream>
#include "Rovers.h"
#include"Emission.h"


class ERover : public Rovers
{
private:

public:
	ERover(int spd, int Checkupdur, int Ncheckup, int Mcomp, Mission* roverMission = 0);
	
	bool isAssigned();

};
