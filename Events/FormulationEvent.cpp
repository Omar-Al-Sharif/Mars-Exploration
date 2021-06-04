#include "FormulationEvent.h"
FormulationEvent::FormulationEvent(char m, int x, int y, float t, float f, int s):Event(x,y) {
	Mtype = m;
	Tlocation = t;
	Fmission = f;
	sig = s;
}
void FormulationEvent::Execute() {

}
FormulationEvent::~FormulationEvent() {

}