#include "Mission.h"
#include "Rovers.h"
#include"ERovers.h"
#include"PRovers.h"
#include "PriQ.h"

class MarsStation
{
private:
	LinkedQueue<Event*> EventList;
	LinkedQueue<Mission> PMissionList;
	PriQ<Emission*> EMissionList;
	LinkedQueue<ERover*> AvailableERoverList;
	LinkedQueue<PRover*> AvailablePRoverList;
	PriQ<Rovers*> In_execution_rover_list;
	LinkedQueue <Mission> CompletedMissionList;
	LinkedQueue<ERover> CheckUpEmg;
	LinkedQueue<PRover> CheckUpPolar;
	int currentDay; //the day we are in
	UI userInterface; //
public:
	void ExecuteAll();
	void outputSim();
	void CallOutputChoice();
	bool AssignRover();
};
