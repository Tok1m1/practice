#pragma once
#include <iostream>
#include <string>
#include <fstream>
#pragma warning(disable : 4996).
using namespace std;
class LogManager {
public:
    static void logMessage(const string& message) {
        ofstream logFile("auth.log", ios_base::app);
        if (logFile.is_open()) {
            time_t now = time(0);
            char* dt = ctime(&now);
            string timestamp(dt);
            timestamp.erase(timestamp.find_last_not_of("\n") + 1);
            logFile << timestamp << " " << message << endl;
            logFile.close();
        }
        else {
            cerr << "Unable to open log file." << endl;
        }
    }
};