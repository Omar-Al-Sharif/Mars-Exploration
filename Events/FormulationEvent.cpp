#include "FormulationEvent.h"
FormulationEvent::FormulationEvent(char m, int d, int missionId, float Location, float f, int s) :Event(missionId,d)
{
	Mtype = m;
	Tlocation = Location;
	missionDuration = f;
	sig = s;
}
Mission& FormulationEvent::Execute(int fd) {
	if (Mtype == 'E')
	{
		Emission m(fd, missionDuration, Tlocation, sig, missionID, Mtype);
	}
	else if (Mtype == 'P')
	{
		Pmission m(fd, missionDuration, Tlocation, sig, missionID, Mtype);
	}
	
	return m;
}
FormulationEvent::~FormulationEvent() {

}
