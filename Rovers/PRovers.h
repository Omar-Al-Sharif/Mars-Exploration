#pragma once
#include <iostream>
#include "Rovers.h"
#include"../Data structure and algorithm/Mission.h"


class PRover : public Rovers
{
private :
	Mission* Pmission;

public :
	void setRoverMission(Mission a);
	Mission* getRoverMission();
};