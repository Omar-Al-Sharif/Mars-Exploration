#include <iostream>
using namespace std;


#include <iostream>
using namespace std;

#include"MarsStation.h"
#include "UI.h"

int main()
{
	MarsStation* mStation;
	mStation->CallOutputChoice();

	do {
		mStation->ExecuteAll(); //Execute All events
		mStation->outputSim();

	} while (!mStation->programEnded());
	mStation->CallOutputFile();


}