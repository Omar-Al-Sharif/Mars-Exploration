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

void MarsStation::AssignErover(Mission* rovermission, ERover* eRover)
{
	eRover->setRoverMission(rovermission);
	rovermission->setEWD(currentDay, eRover->getSpeed());
	Rovers* ptrRover;
	ptrRover = eRover;
	In_execution_rover_list.enqueue(ptrRover);

}


void MarsStation::AssignProver(Mission* rovermission, PRover* pRover)
{
	pRover->setRoverMission(rovermission);
	rovermission->setEWD(currentDay, pRover->getSpeed());
	Rovers* ptrRover;
	ptrRover = pRover;
	In_execution_rover_list.enqueue(ptrRover);
}

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
		Emission* c = p->getEmission();
		EMissionList.enqueue(c);
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
			Emission* ptrEmission; ERover* PtrErover; PRover* ptrProver; Mission* ptrMission; Rovers* ptrRover;
			Pmission* ptrPmission;
			if (!EMissionList.IsEmpty())
			{
				if (!AvailableERoverList.isEmpty())
				{
					
					EMissionList.dequeue(ptrEmission);
					AvailableERoverList.dequeue(PtrErover);
					ptrMission = ptrEmission;
					AssignErover(ptrMission, PtrErover);
				}
				
				else if (!AvailablePRoverList.isEmpty())
				{
					EMissionList.dequeue(ptrEmission);
					AvailablePRoverList.dequeue(ptrProver);
					ptrMission = ptrEmission;
					AssignProver(ptrMission, ptrProver);
				}
			}

			else 
			{
				if (!AvailableERoverList.isEmpty())
				{

					PMissionList.dequeue(ptrPmission);
					AvailableERoverList.dequeue(PtrErover);
					ptrMission = ptrPmission;
					AssignErover(ptrMission, PtrErover);
				}

				else if (!AvailablePRoverList.isEmpty())
				{
					PMissionList.dequeue(ptrPmission);
					AvailablePRoverList.dequeue(ptrProver);
					ptrMission = ptrPmission;
					AssignProver(ptrMission, ptrProver);
				}
			}
		}

	
	//userInterface->ConsoleOutput();//needs modifications for the arguments
	++currentDay;
}


void MarsStation:: CallOutputChoice()
{
	userInterface->outputSimulationChoice();
}



void MarsStation::outputSim()
{
	userInterface->ConsoleOutput(currentDay, PMissionList,EMissionList, AvailableERoverList, AvailablePRoverList, In_execution_rover_list, CheckUpEmg, CheckUpPolar, CompletedMissionList);
}
bool MarsStation::programEnded()
{
	if (In_execution_rover_list.IsEmpty() && PMissionList.isEmpty() && EMissionList.IsEmpty())
	{
		return true;
	}
	return false;
}

void MarsStation::CallOutputFile()
{
	userInterface->OutputFile(CompletedMissionList, AvailableERoverList, AvailablePRoverList);
}

void MarsStation::EnqueueCheckUpLists(Rovers* Just_Finished_Rover)
{
	Just_Finished_Rover->IncrementMissionsComp();
	if (Just_Finished_Rover->NeedsCheckUp())
	{
		Rovers* Type = dynamic_cast<ERover*>(Just_Finished_Rover);
		if (Type)
		{
			ERover* E = (ERover*)Type;
			CheckUpEmg.enqueue(E);
			E->setFinishCheckUp(currentDay);
		}
		else
		{
			PRover* P = (PRover*)Type;
			CheckUpPolar.enqueue(P);
			P->setFinishCheckUp(currentDay);
		}
	}

}

void MarsStation::DequeueCheckUpLists()
{
	ERover* E;
	PRover* P;
	CheckUpEmg.peek(E);
	CheckUpPolar.peek(P);
	while (E->getFinishCheckup() == currentDay)
	{
		CheckUpEmg.dequeue(E);
		AvailableERoverList.enqueue(E);
		CheckUpEmg.peek(E);
	}

	while (P->getFinishCheckup() == currentDay)
	{
		CheckUpPolar.dequeue(P);
		AvailablePRoverList.enqueue(P);
		CheckUpPolar.peek(P);
	}
}
