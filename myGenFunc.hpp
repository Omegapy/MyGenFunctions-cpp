/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*-------------------------------*****************************************----------------------------------
 |                                *                                      *                                 |
 |                                *		  My cpp General Functions       *                                 |
 |                                *                                      *                                 |
 ---------------------------------****************************************----------------------------------*/
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Alejandro Ricciardi (Omegapy)
created date: 01/23/2023


										My cpp General Functions
-----------------------
-- Standalone header --
-----------------------

My cpp General Functions is a collection of my personal c++ functions
for general use and console.

Requirement
c and c++ 17 or later
MS Windows 10 or later

*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef MY_CPP_FUNC_HPP
#define MY_CPP_FUNC_HPP

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*-------------------------------*****************************************----------------------------------
 |                                *                                      *                                 |
 |                                *		          Headers                *                                 |
 |                                *                                      *                                 |
 ---------------------------------****************************************---------------------------------*/
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////

 #include <iostream>		
 #include <cmath>
 #include <string>
 #include <vector>
 #include <fstream>
 #include <windows.h>
 #include <conio.h> // getch()

 //using namespace std;


#include "header.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*--------------------------------****************************************----------------------------------
 |                                *                                      *                                 |
 |                                *	                Classes              *                                 |
 |                                *                                      *                                 |
 ---------------------------------****************************************---------------------------------*/
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*



 */


 //////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |                                *	    Functions  Declarations       *                                 |
  |                                *                                      *                                 |
  ---------------------------------****************************************---------------------------------*/
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////
 
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //----------------------------------------- General Functions ---------------------------------------------------
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
 /*-------------------------------------------------

	Load files
	Handle load file exception.
	Load data into a string vector
	utilizing end-of-line as a separator,
	and returns vector.

	Requirement:
		ifstream

 --------------------------------------------------*/
vector<string> loadFile(string filePath);

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------- Console Functions ---------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*-------------------------------------------------

	Accepts and validates the user input
	if it is an integer.
	Takes a string as an argument
	(question to be displayed),
	and returns the validated integer input.

	Requirement:
		iostream

 --------------------------------------------------*/
int intCheckInput(string question);

/*----------------------------------------------------

	Clears the console screen.

 ----------------------------------------------------*/
void clearScreen(unsigned numLinesToClear);

/*----------------------------------------------------

	Waits for a key to be pressed.

	Requirement:
		conio.h
		clearScreen()

 ----------------------------------------------------*/
void pressKeyToContinue(unsigned numLinesToClear);

/*----------------------------------------------------

	Displays banner

	Requirement:
		iostream
		string

 ----------------------------------------------------*/
void displayBanner(string title);

/*----------------------------------------------------

	Displays a table of data string in the console

	Requirement:
		iostream
		string

 ----------------------------------------------------*/
void displayTable(string tableName, vector<string> &colNames, vector<vector<string>> &dataRows);

/*------------------------------------------------------

	Sets size of the Console's window
	and position the console in desktop screen
	utilizing the variable positionConsole

	position_console values:
		"center", "leftCenter", "rightCenter",
		"topLeft", "topCenter", "topRight",
		"bottomLeft", "bottomCenter", "bottomRight".

	Requirement:
		Windows OS
		string
		windows.h

 --------------------------------------------------------*/
void consoleSize(int consoleWidth, int consoleHeight, string positionConsole);

 

 //////////////////////////////////////////////////////////////////////////////////////////////////////////////
 /*--------------------------------****************************************----------------------------------
  |                                *                                      *                                 |
  |                                *	     Functions  Definitions       *                                 |
  |                                *                                      *                                 |
  ---------------------------------****************************************---------------------------------*/
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////


 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 //----------------------------------------- General Functions ---------------------------------------------------
 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
 

//--------------------------------------------------------------------- Function LoadFile()
/*-------------------------------------------------

	Load files
	Handle load file exception.
	Load data into a string vector
	utilizing end-of-line as a separator,
	and returns vector.

	Requirement:
		ifstream

 --------------------------------------------------*/
vector<string> loadFile(string filePath) 
{
	string line;
	vector<string> lines;

	// Opens the file and assigns to it the variable 
	ifstream file(filePath);

	try { // Error handler

		if (file.is_open()) { // Check if the file opened successfully
			while (getline(file, line)) { // Stores name into a vector
				lines.push_back(line);
			}

			cout << "\n -- The \"" + filePath + "\" opened successfully --\n";

		}
		else { // Throw an exception if the file does not open successely

			throw "-- File Error --";
		}

	}
	catch (char const *fileError) { // Catch the exception if it occurs

		cout << "\n " << fileError << "\n The \"" + filePath + "\" failed to load --\n";

	}

	file.close();
	return lines;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//----------------------------------------- Console Functions ---------------------------------------------------
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//--------------------------------------------------------------------- Function intCheckInput()
/*-------------------------------------------------

	Accepts and validates the user input 
	if it is an integer.
	Takes a string as an argument 
	(question to be displayed),
	and returns the validated integer input.

	Requirement:
		iostream

 --------------------------------------------------*/
int intCheckInput(string question) 
{
	// Local variables
	int userInput;
	char checkInputChar;

	cout << "     " << question;

	do { // Validation loop, checks if the user input is an integer
		cin >> userInput;
		cin.get(checkInputChar); // Gets the first non-digit character, if no non-digit character were found it returns an empty line, 
		// note that '.' in decimals inputs is a non-digit character.
		if (checkInputChar != '\n') {
			cout << "\n      -- The entered input is not a valid input. It should be an integer. --\n     " << question;
			cin.clear(); // clears any error flag on cin
			cin.ignore(1000, '\n'); // ignore anything else on the same line as the non-number so that it does not cause another parse failure
		}
		else {
			break; // Input is an integer 
		}
	} while (true); // True if the input is not an integer

	return userInput;
}

//--------------------------------------------------------------------- Function clearScreen()
/*----------------------------------------------------
                                       
	Clears the console screen.          
                                     
 ----------------------------------------------------*/
void clearScreen(unsigned numLinesToClear) 
{
	// Goes through and displays the number of line to clear the screen console
	for (unsigned i = 0; i < numLinesToClear; i++) {
		cout << "\n";
	}
	cout << endl; // will flush the output buffer and insert a new line.
}


//--------------------------------------------------------------------- Function pressKeyToContinue()
/*----------------------------------------------------
                                   
	Waits for a key to be pressed. 

	Requirement:
		conio.h
		clearScreen()
                                   
 ----------------------------------------------------*/
void pressKeyToContinue(unsigned numLinesToClear) 
{
	// -- Local variables
	// Press key to continue variable
	char ch;

	cout << "\n    -- Press any key to continue -- \n";
	ch = _getch();
	clearScreen(numLinesToClear);
}


//--------------------------------------------------------------------- Function displayBanner()
/*----------------------------------------------------

	Displays banner

	Requirement:
		iostream
		string

 ----------------------------------------------------*/
void displayBanner(string title)
{
	//---- Builds separation lines 
	string line = "\x1B[93m     ";
	for (unsigned i = 0; i < 75; i++) line += "-";
	line += "\033[0m\n";

	//---- Builds row buffer
	string rowBuffer = "\x1B[93m     |";
	for (unsigned i = 0; i < 73; i++) rowBuffer += " ";
	rowBuffer += "|\033[0m\n";

	//---- Builds title row
	string titleRow = "\x1B[93m     |";
	// Left spaces
	unsigned numLeftSpaces = (unsigned)(73 - title.size()) / 2;
	for (unsigned j = 0; j < numLeftSpaces; j++) titleRow += " ";
	titleRow += "\x1B[97m" + title + "\x1B[93m"; // Adds title and its font color
	// Right spaces
	for (unsigned j = 0; j < 73 - (numLeftSpaces + title.size()); j++)  titleRow += " ";
	titleRow += "|\033[0m\n";

	//---- Displays Banner
	cout << "\n\n" << line << rowBuffer << rowBuffer << titleRow << rowBuffer << rowBuffer << line << "\n\n";
}


//--------------------------------------------------------------------- Function displayTable()
/*----------------------------------------------------

	Displays a table of data string in the console

	Requirement:
		iostream
		string

 ----------------------------------------------------*/
void displayTable(string tableName, vector<string> &colNames, vector<vector<string>> &dataRows)
{

	//---- Inserts the column names to the begin of the dataRow vector, making into a table
	dataRows.insert(dataRows.begin(), colNames);

	//---- Computes columns width
	vector<unsigned> columsWidth;
	unsigned colWidth = 0,
		totalColWidth = 0;
	// Loops through columns
	for (unsigned i = 0; i < colNames.size(); i++)
	{
		colWidth = 4;
		// Loops through rows
		for (unsigned j = 0; j < dataRows.size(); j++)
		{
			if (colWidth - 4 < dataRows[j][i].size()) colWidth = (unsigned)dataRows[j][i].size() + 4;
		}

		totalColWidth += colWidth;
		columsWidth.push_back(colWidth);
	}
	// add the the numbers of | to the table total width
	for (unsigned i = 0; i < colNames.size() + 1; i++)
	{
		totalColWidth += 1;
	}

	//---- Build separation lines and rows buffer line
	// Row separation line
	string rowSeparationLine;
	for (unsigned i = 0; i < totalColWidth; i++) rowSeparationLine += "-";
	// Row buffer
	string rowBuffer = "|";
	// Loops through the different columns width
	for (unsigned width : columsWidth)
	{
		for (unsigned i = 0; i < width; i++) rowBuffer += " ";
		rowBuffer += "|";
	}

	cout << "\n\x1B[93m   --- \033[0m" << tableName << "\x1B[93m  ---\033[0m\n";

	//---- Builds the rows of data and displays them
	string rowData;
	unsigned numLeftSpaces;
	bool firstRow = true; // The first row is the column names row, the bool is used to color column names font
	// Loops through the data rows and displays them
	for (vector<string> row : dataRows)
	{
		cout << "   " << rowSeparationLine << "\n   " << rowBuffer << "\n";

		// Builds a row of data and centers the data in the display cells
		rowData = "   |";
		// Loops trough data and displays the row of data
		for (unsigned i = 0; i < row.size(); i++)
		{
			// Adds Left spaces
			numLeftSpaces = (unsigned)(columsWidth[i] - row[i].size()) / 2;
			for (unsigned j = 0; j < numLeftSpaces; j++) rowData += " ";
			// Adds data
			if (firstRow) // The first row is the column names row
			{ 
				rowData += "\x1B[93m" + row[i] + "\033[0m"; // Adds Data and its font color
			}
			else // Not the first row
			{
				rowData += "\x1B[97m" + row[i] + "\033[0m"; // Adds Data and its font color
			}
			// Adds right spaces
			for (unsigned j = 0; j < columsWidth[i] - (numLeftSpaces + row[i].size()); j++)  rowData += " ";
			rowData += "|";
		}

		firstRow = false;
		cout << rowData << "\n   " << rowBuffer << "\n";
	}
	
	cout << "   " << rowSeparationLine << "\n";

} // displayTable()

//--------------------------------------------------------------------- Function consoleSize()
/*------------------------------------------------------

                                                                                       
	Sets size of the Console's window                                                   
	and position the console in desktop screen 
	utilizing the variable positionConsole                        
	
	position_console values:                                                             
		"center", "leftCenter", "rightCenter",                                             
		"topLeft", "topCenter", "topRight",                                               
		"bottomLeft", "bottomCenter", "bottomRight". 

	Requirement:
		Windows OS
		string
		windows.h
                                                                                       
 --------------------------------------------------------*/
void consoleSize(int consoleWidth, int consoleHeight,  string positionConsole)
{
	//-- Local variables
	int consolePositionLeft = 0,
		   consolePositionTop = 0;

	// Creats a structure type rectangle coordinates, upper-left and lower-right corners
	RECT desktop;
	// Gets the desktop screen data 
	HWND myDesktop = GetDesktopWindow();
	// Stores the size of monitor screen to the variable desktop
	GetWindowRect(myDesktop, &desktop);
	/*
		The top left corner of the monitor has the coordinates (0, 0)
		and the bottom right corner has the coordinates (desktop.right, desktop.bottom).
		Note that the desktop.right = monitor lenght
		and the desktop.bottom = monitor width.
	*/
	// Checks if the wanted console lenght is bigger than the monitor screen lenght, 'desktop.right'
	if (desktop.right < consoleWidth) { consoleWidth = (int)floor(desktop.right); }
	// Checks if the wanted console width is bigger than the monitor screen width, 'desktop.bottom'
	if (desktop.bottom < consoleHeight) { consoleHeight = (int)floor(desktop.bottom); }

	// Checks if the wanted console's width or lenght are NOT the same as the width or lenght of the desktop screen
	// if true initializes the console's coordinates to the wanted console position
	// else console_position_left = 0, console_position_top = 0.
	if (consoleWidth != desktop.right || consoleHeight != desktop.bottom) {
		// Checks the wanted position and computes the related coordinates	
		if (positionConsole == "center") {
			consolePositionLeft = (int)round((desktop.right - consoleWidth) / 2);
			consolePositionTop = (int)round((desktop.bottom - consoleHeight) / 2);
		}
		else if (positionConsole == "leftCenter") {
			consolePositionLeft = 10;
			consolePositionTop = (int)round((desktop.bottom - consoleHeight) / 2);
		}
		else if (positionConsole == "rightCenter") {
			consolePositionLeft = (int)round((desktop.right - consoleWidth) - 10);
			consolePositionTop = (int)round((desktop.bottom - consoleHeight) / 2);
		}
		else if (positionConsole == "topLeft") {
			consolePositionLeft = 10;
			consolePositionTop = 10;
		}
		else if (positionConsole == "topCenter") {
			consolePositionLeft = (int)round((desktop.right - consoleWidth) / 2);
			consolePositionTop = 10;
		}
		else if (positionConsole == "topRight") {
			consolePositionLeft = (int)round((desktop.right - consoleWidth) - 10);
			consolePositionTop = 10;
		}
		else if (positionConsole == "bottomLeft") {
			consolePositionLeft = 10;
			consolePositionTop = (int)round((desktop.bottom - consoleHeight) - 40);
		}
		else if (positionConsole == "bottomCenter") {
			consolePositionLeft = (int)round((desktop.right - consoleWidth) / 2);
			consolePositionTop = (int)round((desktop.bottom - consoleHeight) - 40);
		}
		else if (positionConsole == "bottomRight") {
			consolePositionLeft = (int)round((desktop.right - consoleWidth) - 10);
			consolePositionTop = (int)round((desktop.bottom - consoleHeight) - 40);
		}
	}

	// Gets the existing console screen data
	HWND my_console = GetConsoleWindow();
	// Initializes the console to the wanted size and its position to the center of the screen monitor 
	MoveWindow(my_console, consolePositionLeft, consolePositionTop, consoleWidth, consoleHeight, TRUE);

} // console_size()

#endif