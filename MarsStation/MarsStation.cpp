#include "MarsStation.h"

/*
LinkedQueue<Event> EventList;
	LinkedQueue<Mission> PMissionList;
	PriQ<Emission> EMissionList;
	LinkedQueue<ERover> AvailableERoverList;
	LinkedQueue<PRover> AvailablePRoverList;
	PriQ<Rovers> In_execution_rover_list;
	LinkedQueue <Mission> CompletedMissionList;
	LinkedQueue<ERover> CheckUpEmg;
	LinkedQueue<PRover> CheckUpPolar;
*/



MarsStation::MarsStation()
{
	currentDay = 0;
}

void MarsStation::AssignMission(FormulationEvent* p)
{
	p->Execute(currentDay);
	bool b;
	char type = p->gettype();
	if (type=='E')
	{
	    EMissionList.enqueue((p->getEmission()));
		p->getEmission()->setSWD(currentDay);
	}
	else
	{
		Pmission* g = p->getPmission();
		b= PMissionList.enqueue(g);
		p->getEmission()->setSWD(currentDay);
	}
}


void MarsStation::ExecuteAll()
{
	while (!EventList.isEmpty() || !EMissionList.IsEmpty() || !PMissionList.isEmpty() || !In_execution_rover_list.IsEmpty() || !CheckUpPolar.isEmpty() || !CheckUpPolar.isEmpty())
	{
		Event* temp;
		EventList.peek(temp);
		if (temp->getDay() == currentDay)
		{
				
				while (temp->getDay() == currentDay)
				{
					Event* r = dynamic_cast<FormulationEvent*>(temp);
					if (r)
					{
						FormulationEvent* p = (FormulationEvent*)r;
						EventList.dequeue(temp);
						AssignMission(p);
						EventList.peek(temp);
					}
				}
			
		}

		while (!EMissionList.IsEmpty() && !(AvailableERoverList.isEmpty() || (AvailablePRoverList.isEmpty())))
		{
			


		}

	}
	userInterface->ConsoleOutput();//needs modifications for the arguments
	++currentDay;
}
