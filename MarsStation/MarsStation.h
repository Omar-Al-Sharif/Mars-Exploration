#pragma once
#include "Queue.h"
#include "Event.h"
#include "UI.h"
#include "Mission.h"
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
	void  AssignRover();
	void AssignMission(FormulationEvent*p);
	MarsStation();
	bool programEnded(); //check if program ended
	void outputSim();
	void CallOutputChoice(); // Chooose
	void CallOutputFile(); // calls the output file in the end
	void EnqueueCheckUpLists(Rovers* AssignedRover);
	void DequeueCheckUpLists();

};

