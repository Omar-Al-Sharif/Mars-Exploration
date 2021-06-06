#pragma once
#include "Queue.h"
#include "Event.h"
#include "UI.h"
#include "Mission.h"
#include "EMission.h"
#include "PMission.h"
#include "Rovers.h"
#include"ERovers.h"
#include"PRovers.h"
#include "PriQ.h"
#include "Event.h"
class MarsStation
{
private:
	LinkedQueue<Event> EventList;
	LinkedQueue<Pmission> PMissionList;
	PriQ<Emission> EMissionList;
	LinkedQueue<ERover> AvailableERoverList;
	LinkedQueue<PRover> AvailablePRoverList;
	PriQ<Rovers> In_execution_rover_list;
	LinkedQueue <Mission> CompletedMissionList;
	LinkedQueue<ERover> CheckUpEmg;
	LinkedQueue<PRover> CheckUpPolar;
	int currentDay; //the day we are in
	UI* userInterface; //
public:
	void ExecuteAll();
	void outputSim();
	void CallOutputChoice();
	bool AssignRover();
	void AssignMission(FormulationEvent*p);
	MarsStation();

};
