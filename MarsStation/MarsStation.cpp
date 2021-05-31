#include "MarsStation.h"


void MarsStation::ExecuteAll()
{
	while (!EventList.isEmpty())
	{
		Event* temp;
		EventList.peek(temp);
		if (temp->getday() == currentDay) //TODO getday() function in event classes
		{
			
			while (temp->getday() == currentDay)
			{
				EventList.dequeue(temp);
				temp->Execute();
				EventList.peek(temp);
			}
		}
		userInterface.ConsoleOutput();//needs modifications for the arguments
		++currentDay;
	}
}