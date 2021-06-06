#include "Emission.h"

Emission::Emission(int fd, int md, int targetloc, int significance, int Id) : Mission(fd, md, targetloc,significance, Id)
{
	setPriority();
}

void Emission::setPriority()
{
	//write the piroity equation  
}

int Emission::getPriority() const
{
	return Priority;
}
