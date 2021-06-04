#pragma once
#include "Event.h"
class FormulationEvent :public Event
{
private:
	float Tlocation; //the missionís target location (in kilometers from the base station)
	float Fmission; // number of days needed to fulfill the mission requirements at target location
	int sig; // missionís significance
	char Mtype;
public: 
	FormulationEvent(char m,int x,int y,float t,float f,int s);
	void Execute();
	~FormulationEvent();
};

