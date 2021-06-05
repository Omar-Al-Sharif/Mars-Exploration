#include "FormulationEvent.h"
FormulationEvent::FormulationEvent(char m, int d, int missionId, int Location, int f, int s) :Event(missionId, d)
{
	Mtype = m;
	Tlocation = Location;
	missionDuration = f;
	sig = s;
}

	Mission* FormulationEvent::Execute(int fd) 
	{
		
		if (Mtype == 'E')
		{
			return &Emission(fd, missionDuration, Tlocation, missionID);
		}
		else if (Mtype == 'P')
		{
			return &Pmission(fd, missionDuration, Tlocation, missionID);
		}
	}
	FormulationEvent::~FormulationEvent() 
	{

	}
