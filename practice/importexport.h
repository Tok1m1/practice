#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "log.h"
#include "autorization.h"
#pragma warning(disable : 4996).
using namespace std;
SessionManager session2;
void importdata()
{
	string locate;
	string line;
	getline(cin, locate);
	getline(cin, locate);
	fstream MyFile(locate);
	fstream MyFile1("work.txt", ios_base::app);
	if (MyFile.is_open())
	{
		//int i = 1;
		//while (getline(MyFile, line1))
		while (!MyFile.eof())
		{
			MyFile >> line;
			MyFile1 << line << endl;
		}
	}
	MyFile.close();
	
	MyFile1.close();


}
void exportdata()
{
	string locate;
	string line;
	getline(cin, locate);
	getline(cin, locate);
	fstream MyFile(locate, ios_base::app);
	fstream MyFile1("work.txt");
	if (MyFile1.is_open())
	{
		//int i = 1;
		//while (getline(MyFile, line1))
		while (!MyFile1.eof())
		{
			MyFile1 >> line;
			MyFile << line << endl;
		}
	}
	MyFile1.close();
	MyFile.close();
}
void importlog()
{
	string currentUser = session2.getCurrentUser();
	LogManager::logMessage("Import log: " + currentUser);
}
void exportlog()
{
	string currentUser = session2.getCurrentUser();
	LogManager::logMessage("Export log: " + currentUser);
}