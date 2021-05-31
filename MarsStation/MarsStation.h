#pragma once
#include "Queue.h"
#include "Event.h"
#include "UI.h"
#include "Mission.h"

class MarsStation
{
private:
	LinkedQueue<Event *> EventList;
	LinkedQueue<Mission> MissionList;
	int currentDay; //the day we are in
	UI userInterface;
public:
	void ExecuteAll();
};
