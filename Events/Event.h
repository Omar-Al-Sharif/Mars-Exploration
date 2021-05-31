#pragma once
//inputs are put in the event list
class Event
{
protected:
	int day;//event day
	int missionID; //mission Id
public:
	Event();
	virtual void Execute() = 0;
	
	virtual ~Event();
};