-----------------------------------------------------------------------------------------------------------------------------
My cpp General Functions
-----------------------------------------------------------------------------------------------------------------------------

 Alejandro Ricciardi (Omegapy)  
 created date: 01/23/2023  
 									
-- Standalone header --

My cpp General Functions is a collection of my personal c++ functions
for general use and console.

![image](https://user-images.githubusercontent.com/121726699/214980993-35dd3e1a-08f5-41a2-9a90-49e4086d1b88.png)



-----------------------------------------------------------------------------------------------------------------------------
Requirements:

c++ 17 or later  
MS Windows 10 or later

-----------------------------------------------------------------------------------------------------------------------------

```cpp
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
```

-----------------------------------------------------------------------------------------------------------------------------

Links:  
 Project GitHub: https://github.com/Omegapy/MyGenFunctions-cpp  
 GitHub: https://github.com/Omegapy   
 YouTube: https://www.youtube.com/@omegapy (new)  

