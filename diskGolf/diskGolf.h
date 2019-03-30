#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

static double percentageFactor = 0.80; //Added a static variable for the percentage factor for the handicap

class Golfer
{
	// attributes
private:
	string firstName;
	string lastName;
	string iD;
	int games;
	int tosses;
	double tossAvg;

	//methods
public:
	//constructor
	Golfer(string golferFN, string golferLN, string golferID, int golferGames, int golferTosses)
	{
		firstName = golferFN;
		lastName = golferLN;
		iD = golferID;
		games = golferGames;
		tosses = golferTosses;
		tossAvg = golferTosses / golferGames;
	}

	//Accessor Methods
	string getFN()
	{
		return firstName;
	}

	string getLN()
	{
		return lastName;
	}

	string getID()
	{
		return iD;
	}

	int getGames()
	{
		return games;
	}

	int getTosses()
	{
		return tosses;
	}

	double getAvg()
	{
		return tossAvg;
	}

	double getPercentageFactor() //Added the get method for the percentage factor
	{
		return percentageFactor;
	}

	//Mutator Methods
	void nameChange(string newFN, string newLN) //Allows the user to change thier name
	{
		firstName = newFN;
		lastName = newLN;
	}

	void iDChange(string newID) //Allows the user to change thier ID number
	{
		iD = newID;
	}

	//AddScore method
	void addScore(double newTosses) /*Adds the players' scores and finds thier avg.s by dividing their
									tosses over the games they played*/
	{
		tosses = tosses + newTosses;
		games += 1;
		tossAvg = tosses / games;
	}
};