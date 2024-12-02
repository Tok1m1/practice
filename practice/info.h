#pragma once
#include <iostream>
#include <string> 
#include <vector> 
#include <fstream> 
#include <algorithm> 
#include <iterator>  
#include "log.h"
#include "autorization.h"
#pragma warning(disable : 4996).
using namespace std;
SessionManager session;
void add_text()
{
    string f;
    ofstream MyFile("work.txt", ios_base::app);
    //MyFile.open(ad);
    getline(cin, f);
    getline(cin, f);
    MyFile << f << endl;









}
void rem() {
    string idDel;
    getline(cin, idDel);
    getline(cin, idDel);
    ifstream path("work.txt");
    ofstream pathTemp("temp.txt");
    string strId;
    while (!path.eof()) {
        path >> strId;

        if (strId != idDel)
        {
            pathTemp << strId << " " << endl;

        }
    }
    path.close();
    pathTemp.close();
    string table = "work.txt";
    const char* p = table.c_str();
    remove(p);
    rename("temp.txt", "work.txt");

}
 
void show()
{
    string line;
    ifstream MyFile("work.txt");
    if (MyFile.is_open())
    {
        while (getline(MyFile, line))
        {
            cout << line << std::endl;
        }
    }
    MyFile.close();
}

void showlog()
{
    string currentUser = session.getCurrentUser();
    LogManager::logMessage("View file: " + currentUser);
}
void addlog()
{
    string currentUser = session.getCurrentUser();
    LogManager::logMessage("Add text in file: " + currentUser);
}
void deletelog()
{
    string currentUser = session.getCurrentUser();
    LogManager::logMessage("Delete text: " + currentUser);
}
