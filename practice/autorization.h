#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "log.h"
#pragma warning(disable : 4996).
using namespace std;
class User {
public:
    string username;
    string hashedPassword;
    string role;

    User() {}
    User(string uname, string pwd, string r) : username(uname), hashedPassword(pwd), role(r) {}
};
class SessionManager {
private:
    string currentUser;
    string currentRole;

public:
    void login(const string& username, const string& role) {
        currentUser = username;
        currentRole = role;
        cout << "Logged in as " << currentUser << " (" << currentRole << ")" << endl;
    }

    void logout() {
        if (!currentUser.empty()) {
            cout << "Logged out " << currentUser << endl;
            currentUser.clear();
            currentRole.clear();
        }
        else {
            cout << "No user logged in." << endl;
        }
    }

    bool isLoggedIn() const {
        return !currentUser.empty();
    }

    string getCurrentRole() const {
        return currentRole;
    }

    string getCurrentUser() const {
        return currentUser;
    }
};

class AuthManager {
private:
    string userDataFile;
    SessionManager session;

    string hashPassword(const string& password) {
        string hashed = "hashed_";
        hashed += password;
        return hashed;
    }

    bool userExists(const string& username) {
        ifstream users(userDataFile);
        string line;
        while (std::getline(users, line)) {
            size_t firstComma = line.find(',');
            if (firstComma != std::string::npos) {
                string storedUsername = line.substr(0, firstComma);
                if (storedUsername == username) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    AuthManager(string file = "users.txt") : userDataFile(file) {}

    bool registerUser(const string& username, const string& password, const string& role = "user") {
        if (userExists(username)) {
            cerr << "User already exists." << endl;
            LogManager::logMessage("Registration attempt failed for user: " + username);
            return false;
        }

        string hashedPwd = hashPassword(password);
        ofstream users(userDataFile, ios_base::app);
        if (users.is_open()) {
            users << username << "," << hashedPwd << "," << role << endl;
            users.close();
            LogManager::logMessage("User registered: " + username + " with role " + role);
            return true;
        }
        else {
            cerr << "Unable to open user data file for writing." << endl;
            return false;
        }
    }

    bool loginUser(const string& username, const string& password) {
        ifstream users(userDataFile);
        string line;
        while (getline(users, line)) {
            size_t firstComma = line.find(',');
            size_t secondComma = line.find(',', firstComma + 1);
            if (firstComma != string::npos && secondComma != std::string::npos) {
                string storedUsername = line.substr(0, firstComma);
                string storedPassword = line.substr(firstComma + 1, secondComma - firstComma - 1);
                string storedRole = line.substr(secondComma + 1);
                if (storedUsername == username && storedPassword == hashPassword(password)) {
                    session.login(username, storedRole);
                    LogManager::logMessage("User logged in: " + username);
                    cout << "Login successful." << std::endl;
                    return true;
                }
            }
        }
        LogManager::logMessage("Failed login attempt for user: " + username);
        cout << "Login failed. Invalid username or password." << std::endl;
        return false;
    }

    void logoutUser() {
        string currentUser = session.getCurrentUser();
        session.logout();
        LogManager::logMessage("User logged out: " + currentUser);
    }

    bool isAdmin() const {
        return session.isLoggedIn() && session.getCurrentRole() == "admin";
    }

    bool isLoggedIn() const {
        return session.isLoggedIn();
    }
};
/*string autoriz();*/