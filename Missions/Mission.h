#pragma once

#include "Rovers.h"

class Mission
{

private:
	int FD; //Formulation day of the mission
	int MD; //Mission Duration
	int ED; //Execution Days: The amount of days in execution for the mission 
	int leftDays; // the amount of days till the mission ends
	int targetlocation;
	int WD; //Waiting Days before the mission is executed
	int CD; //Completion day is the finish time
	// Equation of consumptionDays = 2*(TargetLocation*RoverSpeed)/25 +MD;
	Rovers* R; //Rover assigned to the mission

public:
	Mission(int fd, int md, int targetloc);
	void assigntoRover(Rovers* R);
	void setWaitingDays(int wd);
	int getFinishDay() const;
};
