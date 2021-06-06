#include "Emission.h"
Emission::Emission()
{

}
Emission::Emission(int fd, int md, int targetloc, int Id, int significance) : Mission(fd, md, targetloc, Id,significance)
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
