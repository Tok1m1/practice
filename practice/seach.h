#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include "log.h"
#include "autorization.h"
#include "info.h"
#pragma warning(disable : 4996).
using namespace std;
SessionManager session1;
void search()
{
	string line2;
	string line1;
	getline(cin, line2);
	getline(cin, line2);
	fstream MyFile("work.txt", ios_base::in);
	if (MyFile.is_open())
	{
		int i = 1;
		//while (getline(MyFile, line1))
		while(!MyFile.eof())
		{
		MyFile >> line1;
		if (line1.find(line2) != string::npos) {
			cout << " Find entry on " << i << " place\n";
			cout << "You found " << line2;
			break;
		}
			
		}
		if (i == 1) {
			cout << "Not found";
		}
		
	}
	
	MyFile.close();

}
bool comp(string a, string b) {
	return a < b;
}
void sorting()
{
	vector<string> tort;
	string line1;
	fstream MyFile("work.txt", ios_base::in);
	if (MyFile.is_open())
	{
		//int i = 1;
		//while (getline(MyFile, line1))
		while (!MyFile.eof())
		{
			MyFile >> line1;
			tort.push_back(line1);
		}
	}
	sort(tort.begin(), tort.end(),comp);
	for (auto i : tort) {
		cout << i << "\n";
	}
}




void seachlog()
{
	string currentUser = session1.getCurrentUser();
	LogManager::logMessage("Seach log: " + currentUser);
}
void sortlog()
{
	string currentUser = session1.getCurrentUser();
	LogManager::logMessage("Sort log: " + currentUser);
}