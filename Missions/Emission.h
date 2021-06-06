#pragma once
#include "Mission.h"

class Emission :  public Mission
{
private:
	double Priority;

public:
	Emission();
	Emission(int fd, int md, int targetloc ,int Id);
	void setPriority();
	int getPriority() const;
};

