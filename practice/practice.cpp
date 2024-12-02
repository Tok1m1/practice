#include <iostream>
#include <string>
#include "autorization.h"
#include "log.h"
#include "info.h"
#include "seach.h"
#include "importexport.h"
#pragma warning(disable : 4996).
using namespace std;



int main()
{
    AuthManager auth("users.txt");


    int choice;
    do {
        cout << "\n--- Authentication System ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        if (auth.isLoggedIn()) {
            cout << "3. Logout\n";
            
            if (auth.isAdmin()) {
                cout << "4. Admin Panel\n";
                cout << "5. Add text\n";
                cout << "6. Delete text\n";
            }
            cout << "7. Show text\n";
            cout << "8. Search text\n";
            cout << "9. Sort text\n";
            cout << "10. Import data\n";
            cout << "11. Export data\n";
        }

        cout << "12. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        string username, password, role;

        switch (choice) {
        case 1:
            cout << "Enter username: ";
            cin.ignore();
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);
            cout << "Enter role (user/admin): ";
            getline(cin, role);
            auth.registerUser(username, password, role);
            break;
        case 2:
            cout << "Enter username: ";
            cin.ignore();
            getline(cin, username);
            cout << "Enter password: ";
            getline(cin, password);
            auth.loginUser(username, password);
            break;
        case 3:
            auth.logoutUser();
            break;
        case 4:
            if (auth.isAdmin()) {
                cout << "Welcome to the Admin Panel." << std::endl;


            }
            else {
                cout << "Access denied." << std::endl;
            }
            break;
        case 5:
            if (auth.isAdmin()) {
                cout << "Welcome to the File settings." << endl;
                add_text();
                addlog();

            }

            else {
                cout << "Access denied." << std::endl;
            }
            break;
        case 6:
            if (auth.isAdmin()) {
                cout << "Welcome to the File settings." << std::endl;
                rem();
                deletelog();
            }
            else {
                cout << "Access denied." << std::endl;
            }
            break;
        case 7:
            show();
            showlog();
            break;
        case 8:
            search();
            seachlog();
            break;
        case 9:
            sorting();
            sortlog();
            break;
        case 10: 
            importdata();
            importlog();
            break;
        case 11:
            exportdata();
            exportlog();
            break;

        case 12:
            LogManager::logMessage("Program exited.");
            cout << "Exiting program." << std::endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 12);

    return 0;
}
