/*
Mason Henry
C++
Due: October 10th, 2019
To input hourly temperatures from a file and output them as a barchart to the screen.
*/

//I didn't know if we needeed pre and post conditions for if statements so I did them anyway.

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//Function that will be used to output stars to the left of |.
void starleft(float temp, float starcount);
//Function that will be used to output stars to the right of |.
void starright(float temp, float starcount);

int main()
{
	//Sets the identifier for the temperatures that are to be inputted as a float
	float temp;
	
	//Sets up the File stream and opens it.
	string tempval = "C:/Users/jhphoto/Desktop/Mason Scripts/Lab 4/Temperature Values.dat";
	ifstream inFile;
	inFile.open(tempval);
	
	//Preconditions: The input file must be invalid or in this case not found
	//Postcondition: Informs the user of the problem and terminates the program returning 1
	if (!inFile)
	{
		cout << "Can't find the input file please. Double check that the slashes are forward and that it is in the correct location";
		return 1;
	}

	//Priming read
	inFile >> temp;

	//Outputs the bar chart label
	cout << "Temperatures:\n";
	cout << setw(10) << "-30" << setw(9) << "0" << setw(10) << "30" << setw(10) << "60" << setw(10) << "90" << setw(12) << "120\n";
	
	//Precondition: The inFile must be vaild/the temperature must be vaild. 
	//Postcondition: Properly outputs the remainder of the chart and outputing error statements when needed.
	while (inFile)
	{
		//This calculates the number of stars that are needed to be outputted as a float identifier
		float starcount = temp / float(3);

		starleft(temp, starcount);

		starright(temp, starcount);

		//Preconditions: The inFile must be Valid. The temperature must be greater than 120 or less than -30.
		//Postconditions: Informs the user that the value is outside the range.
		if (temp < -30 || temp > 120)
			cout << "Sorry the inputted data value of" << " " << temp << " is outside the range\n";
		
		//Inputs the next value from the file and stores it as the identifier temp so that the loop can star over as long
		//as it is valid.
		inFile >> temp;
	}
	//Preconditions: The temperature must be invalid putting the stream in a failed state. For example, a character is entered.
	//Postconditions: Let's the user know that an invalid temperature has been inputted and terminates the program returning 1.
	if (!temp)
	{
		cout << "Inputted an invalid temperature please double check temperatures.\n";
		return 1;
	}

	//Closes the file stream.
	inFile.close();

	return 0;
}

void starleft(float temp, float starcount)
{
	//Preconditions:Stream must be valid. Temperature must be between 0 and -30.
	//Postconditions: Outputs the Correct number of stars to the left of the | and continues running.
	if (temp < 0 && temp >= -30)
	{
		//Outputs the temp with three decimal places along the left hand side of the screen and sets proper width so 
		//the |'s line up.
		cout << setw(7) << fixed << setprecision(3) << temp << setw(12 + starcount);
		//Preconditions: Starcount must be negative. Temp must be between 0 and -30. Stream must not be in a failed state.
		//Postconditions: Outputs the correct number of stars on the left side of the | and continues running.
		while (starcount < 0)
		{
			starcount++;
			cout << "*";
		}
		cout << "|\n";
	}
}

void starright(float temp, float starcount)
{
	//Preconditions: Stream must be valid. Temperautre must be between 0 and 120 including 0.
	//Postconditions: Outputs the correct number of stars to the right of the | and continues running.
	if (temp >= 0 && temp <= 120)
	{
		//Outputs the temp with three decimal places along the left hand side of the screen and sets proper width so
		//the | lines up under 0.
		cout << setw(7) << fixed << setprecision(3) << temp << setw(12) << "|";
		//Preconditions: Starcount must be positive. Temp must be between 0 and 120 including 0. Stream must be valid
		//Postconditions: Outputs the correct number of stars to the right of the | and continues running.
		while (starcount > 0)
		{
			starcount--;
			cout << "*";
		}
		cout << endl;
	}
}













































































//Hello again. Did you find me last time?