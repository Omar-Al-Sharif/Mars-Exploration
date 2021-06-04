#include "FormulationEvent.h"
FormulationEvent::FormulationEvent(char m, int d, int missionId, float Location, float f, int s) :Event(missionId,d)
{
	Mtype = m;
	Tlocation = Location;
	missionDuration = f;
	sig = s;
}
void FormulationEvent::Execute() {

}
FormulationEvent::~FormulationEvent() {

}
