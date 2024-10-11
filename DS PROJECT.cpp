// DS PROJECT.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "graph.h"
#include <fstream>

void printLogin();
int printMenu();

int main()
{
	printLogin();
	string fn;
	cout << "\nEnter filename along with file extension: ";
	cin >> fn;
	ifstream fin;
	fin.open(fn);
	if (!fin)
	{
		cout << "\n<ERROR! UNABLE TO OPEN FILE '" << fn << "'>\n"
			<< "File is missing from default/given path.\n\n";
		exit(1);
	}
	cout << endl;
	int nOfNodes = 0;
	fin >> nOfNodes;
	graph* G = new graph(nOfNodes);
	int x = 0, y = 0, w = 0;
	while (!fin.eof())
	{
		fin >> x >> y >> w;
		cout << "Adding edge '" << x << " - " << y << "' with weight " << w << "...\n";
		G->insertEdge(x, y, w);
	}
	fin.close();
	cout << "\nAll edges has been added to the graph successfully.\n\n";
	system("pause");
	system("cls");
	int* mst = nullptr;
	int m = printMenu();
	while (m != 0)
	{
		if (m == 1)
		{
			mst = G->make_MST_via_PrimAlgo();
			cout << "\nMST has been made successfully via Prim's Algorithm.\n\n";
		}
		else if (m == 2)
			G->printMST(mst);
		else
		{
			if (mst)
				cout << "\nTotal weight of MST: " << G->getMSTWeight(mst) << endl << endl;
		}
		system("pause");
		system("cls");
		m = printMenu();
	}
	delete G;
}
void printLogin()
{
	string p = "admin", password = "";
	char c;
	ifstream fin;
	fin.open("password.txt");
	if (fin)
		fin >> p;
	fin.close();
	cout << "                                      -----------------\n"
		<< "                                      |      PROJECT   |\n"
		<< "                                      -----------------\n"
		<< "---------------------------------------------------------------------------------------------\n"
		<< "|                          FIBER OPTIC TRAJECTORY OPTIMIZING SYSTEM                         |\n"
		<< "---------------------------------------------------------------------------------------------\n"
		<< "                                          ---------\n"
		<< "                                          | LOGIN |\n"
		<< "                                          ---------\n\n"
		<< "Enter Admin Password: ";

	while ((c = _getch()) != '\r') {
		password += c;
		cout << "*";
	}

	if (password != p)
	{
		cout << "\nWRONG PASSWORD! EXITING...\n\n";
		exit(1);
	}
	system("cls");
}

int printMenu()
{
	int n = 0;
	cout << "                                      -----------------\n"
		<< "                                      |     PROJECT    |\n"
		<< "                                      -----------------\n"
		<< "---------------------------------------------------------------------------------------------\n"
		<< "|                          FIBER OPTIC TRAJECTORY OPTIMIZING SYSTEM                         |\n"
		<< "---------------------------------------------------------------------------------------------\n"
		<< "| 0 = EXIT PROGRAM                                                                          |\n"
		<< "| 1 = MAKE MST VIA PRIM'S ALGORITHM                                                         |\n"
		<< "| 2 = PRINT MST                                                                             |\n"
		<< "| 3 = CALCULATE MST WEIGHT                                                                  |\n"
		<< "---------------------------------------------------------------------------------------------\n\n"
		<< "Enter your choice: ";
	cin >> n;
	while (n < 0 || n > 3)
	{
		cout << "\n<ERROR! INVALID INPUT>\nEnter again: ";
		cin >> n;
	}
	return n;
}