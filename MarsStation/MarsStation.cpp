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
	p->Execute(currentDay); //note that setting the starting of waiting days is done here automatically when creating mission
	bool b;
	char type = p->gettype();
	if (type=='E')
	{
	    EMissionList.enqueue((p->getEmission()));
	}
	else
	{
		Pmission* g = p->getPmission();
		b= PMissionList.enqueue(g);
	}
}


void MarsStation::AssignRover()
{

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

		while ((!AvailableERoverList.isEmpty() || !AvailablePRoverList.isEmpty()) && (!EMissionList.IsEmpty() || !PMissionList.isEmpty()))
		{
			if (!EMissionList.IsEmpty())
			{
				Emission* ptrEmission; ERover* PtrErover; PRover* ptrProver;
				if (!AvailableERoverList.isEmpty())
				{
					EMissionList.dequeue(ptrEmission);
					AvailableERoverList.dequeue(PtrErover);
					PtrErover->setRoverMission((Mission*)ptrEmission);


				}
			}


		}

	}
	userInterface->ConsoleOutput();//needs modifications for the arguments
	++currentDay;
}
