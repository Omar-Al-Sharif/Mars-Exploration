#pragma once
#include "Event.h"


#pragma once
#include "Event.h"
class FormulationEvent :public Event
{
private:
	float Tlocation; //the mission’s target location (in kilometers from the base station)
	float missionDuration; // number of days needed to fulfill the mission requirements at target location
	int sig; // mission’s significance
	char Mtype;
public:
	FormulationEvent(char m, int x, int y, float t, float f, int s);
	void Execute();
	~FormulationEvent();
};
