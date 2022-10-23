/*Shannon Walden
10/15/2022
Project 3*/
#include <Python.h>
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>
#include <string>
#include <fstream>
#include <sstream>





using namespace std;


/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}
void showMenu() { //function to show the menu

	cout << "*** MENU ***" << endl;
	cout << endl;
	cout << "1: Get a list of how many times all items were purchased" << endl;
	cout << "2: Get how many times an item was purchased" << endl;
	cout << "3: Print Histogram of items purchased" << endl;
	cout << "4: Exit" << endl;
	cout << "Enter your selection as a number 1, 2, 3, or 4 ." << endl;
	cout << endl;
}
void menuSelection() { //function for the menu optuons
	string menuInput;
	int numInput;
	string wordInput;
	cin >> menuInput; //menu selection from the user
	cout << endl;
	char firstletter = menuInput.front(); //assigns the first character in the string input
	while (firstletter != '1' && firstletter != '2' && firstletter != '3' && firstletter != '4') { //checks if the first letter of the input is 1,2,3, or 4 keeps looping if not
		cout << "Please enter 1, 2, 3, or 4." << endl;
		cin.clear();
		cin >> menuInput;
		firstletter = menuInput.front();
	}

	if (menuInput == "1") { //switch case for menu options
		cout << endl;
		CallProcedure("GetAllWordCount"); //calls the python function GetAllWordCount
		cout << endl;
	}
	else if (menuInput == "2") {
		cout << "What word would you like to look for?"; //asks user for the input
		cout << endl;
		cin >> wordInput;
		callIntFunc("GetWordCount", wordInput); //takes user input into the python function GetWordCount
		cout << endl;
	}
	else if (menuInput == "3") {
		CallProcedure("MakeNewFile"); //calls the MakeNewFile function in the python code
		ifstream frequencyFile{};
		frequencyFile.open("frequency.dat"); //opens the file that was created in python
		string mystring;
		string frequency_word;
		int frequency_num;
		frequencyFile >> frequency_word;
		frequencyFile >> frequency_num;
		//loop for each line to print 
		while (!frequencyFile.fail()) {
			cout << setw(20)<< left << frequency_word;//sets the words to be on the left with a width of twenty
			for (int i = 0; i < frequency_num; i++) {
				printf("\x1B[95m*\033[0m"); //prints * in magenta
			}
			cout << endl;
			frequencyFile >> frequency_word;
			frequencyFile >> frequency_num;
		}
		frequencyFile.close(); //closes the file
		cout << endl;
	}
	else { //exits if user selects 4

	}

	}


void main()
{
	showMenu(); //displays the menu
	cout << endl;
	cout << endl;
	menuSelection(); //lets the user select from the menu

	;
}

			

	


		


		

			
		







			
		


	


