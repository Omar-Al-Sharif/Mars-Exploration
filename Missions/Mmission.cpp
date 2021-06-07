#pragma once
#include "Mmission.h"
#include "Mission.h"
Mmission::Mmission(int fd, int md, int targetloc, int Id, int signficance) : Mission(fd, md, targetloc, Id, signficance)
{
	setMissionType('M');
}