#include "Mission.h"

class Emission: public Mission
{

private:
	double Priority;

public:
	Emission(int fd, int md, int targetloc);
	friend bool operator>(const Emission & E1, const Emission & E2);
};
