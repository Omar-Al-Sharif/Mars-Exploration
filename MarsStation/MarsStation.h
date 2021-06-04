#pragma once
#include "Queue.h"
#include "Event.h"
#include "UI.h"
#include "Mission.h"
#include "Rovers.h"
#include"ERovers.h"
#include"PRovers.h"

class MarsStation
{
private:
	LinkedQueue<Event *> EventList;
	LinkedQueue<Mission> PMissionList;
	LinkedQueue<ERover> AvailableERoverList;
	LinkedQueue<PRover> AvailablePRoverList;

	int currentDay; //the day we are in
	UI userInterface; //
public:
	void ExecuteAll();
	void outputSim();
	void CallOutputChoice();
};
