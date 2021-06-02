#pragma once
#include <iostream>
#include "Rovers.h"
#include"Mission.h"


class ERover : public Rovers
{
private:
	Mission* Emission;


public:
	void setRoverMission(Mission a);
	Mission* getRoverMission();

};