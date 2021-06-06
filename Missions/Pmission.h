#pragma once
#include "Mission.h"
class Pmission : public Mission
{
private:


public:
	Pmission(int fd, int md, int targetloc, int significance, int Id);
	Pmission();
};
