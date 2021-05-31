#pragma once
// Choosing Simulation mode
//Input operation is done hereee
//Output if this mode is chosen
#include <iostream>
using namespace std;
#include <fstream>

#include "MarsStation.h"
#include "FormulationEvent.h"
#include "CancelEvent.h"
#include "PromotionEvent.h"

class MarsStation;

class UI
{
private:
	ofstream output;
	ifstream input;
	int choice;
public:
	void inputData();
	void outputSimulationChoice();
	void ConsoleOutput(); //outputs based on the choice of program interface
};

void UI::inputData()
{
	input.open("inputFile.txt");

	if (input.fail())
	{
		cerr << "Error!! Opening file" << endl;
		exit(1);
	}

	int MRN; // Mountainous rovers number
	int PRN; // Polar Rovers number
	int ERN; // Emergency Rovers number
	input >> MRN >> PRN >> ERN;
	int SM; //mountainous Rover Speed
	int SP;
	int SE;
	int N; //number of missions the rovers do before checkup
	int CM; //chedckup mountainous
	int CP; // Checkup Polar
	int CE; //checkup Emergency
	int AutoP;
	int numberEvents; //number of events
	input >> SM >> SP >> SE;
	input >> N >> CM >> CP >> CE;
	input >> AutoP;
	input >> numberEvents;
	char eventType;

	while (!input.eof())
	{
		input >> eventType;
		if (eventType == 'F')
		{
			//add to event list
			// F event list
			FormulationEvent* e;
			
		}
	}
}

void UI::outputSimulationChoice() //chooses the type of simulation from choice
{
	cout << "Choose Program interface(from 1 to 3 inclusive):" << endl;
	cout << "1-Interactive Mode" << endl;
	cout << "2- Step by Step Mode" << endl;
	cout << "3- Silent Mode" << endl;
	int choiceN;
	cin >> choiceN;
	while (!(choiceN >= 1 && choiceN <=3))
	{
		cout << "Error! The choice you entered is not within range." << endl;
		cout << "Enter again:";
		cin >> choiceN;
	}
	this->choice = choiceN;
}

void UI::ConsoleOutput() //needs day,mission list(s),rover list(s)
{

}
