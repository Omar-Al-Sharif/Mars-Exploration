#pragma once

#include "../Data structure and algorithm/ArrayStack.h"
#include "Rovers.h"


class Mission
{

private:
	int FD; //Formulation day of the mission
	int MD; //Mission Duration
	int consumptionDays; // The amount of days in execution for the mission 
	int leftDays; // the amount of days till the mission ends
	// Equation of consumptionDays = 2*(TargetLocation*RoverSpeed)/25 +MD;
	//
	Rovers* R; //Rover assigned to the mission

public:
	Mission();
	void assigntoRover(Rovers* R);

};
