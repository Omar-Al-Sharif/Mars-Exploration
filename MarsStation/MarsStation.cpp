#include "MarsStation.h"
/*

LinkedQueue<Event*> EventList;
	LinkedQueue<Mission> PMissionList;
	PriQ<Emission> EMissionList;
	LinkedQueue<ERover> AvailableERoverList;
	LinkedQueue<PRover> AvailablePRoverList;
	PriQ<Rovers*> In_execution_rover_list;
	LinkedQueue <Mission> CompletedMissionList;
	LinkedQueue<ERover> CheckUpEmg;
	LinkedQueue<PRover> CheckUpPolar;
*/

void MarsStation::ExecuteAll()
{
	while (!EventList.isEmpty() || !EMissionList.IsEmpty() || !PMissionList.isEmpty() || !In_execution_rover_list.IsEmpty())
	{
		Event* temp;
		EventList.peek(temp);
		if (temp->getDay() == currentDay)
		{
				
				while (temp->getDay() == currentDay)
				{
					Event* r = dynamic_cast<FormulationEvent*>(temp);
					FormulationEvent* p = (FormulationEvent*)r;
					if (r)
					{
						EventList.dequeue(temp);
						Emission* e = (Emission*)p->Execute(currentDay);
						if (e)
						{
							e->setSWD(currentDay);
							EMissionList.enqueue(e);
						}
						else
						{
							Pmission* e = (Pmission*)p->Execute(currentDay);
							e->setSWD(currentDay);
							PMissionList.enqueue(*e);
						}
						EventList.peek(temp);
					}
				}
			
		}

		while (!EMissionList.IsEmpty() && !(AvailableERoverList.isEmpty() || (AvailablePRoverList.isEmpty())))
		{
			


		}

	}
	userInterface.ConsoleOutput();//needs modifications for the arguments
	++currentDay;
}
