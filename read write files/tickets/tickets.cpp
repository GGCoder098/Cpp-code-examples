#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
using namespace std;




struct trains {
    string route;
    string time;
    string t_class;
    int tickets;
};

int main() {
    vector<trains> train;
    trains Trip1;
    ifstream info("info.txt");
    string line;
    for (int i = 0; i < 4; i++) {
        if (i == 0) {
            getline(info, line);
            Trip1.route = line;
        }
        else if (i == 1) {
            getline(info, line);
            Trip1.time = line;
        }
        else if (i == 2) {
            getline(info, line);
            Trip1.t_class = line;
        }
        else {
            getline(info, line);
            Trip1.tickets = stoi(line);
        }
    }
    int loop = 0;
    while (loop == 0) {
        cout << "1 - find train   2- buy ticket: ";
        int choice;
        
        cin >> choice;
        if (choice == 1) {
            cout << "enter the name of the city you want to go to: ";
            string city;
            cin.ignore();
            getline(cin, city);
            string temp = Trip1.route;
            if (temp.find(city) == 0 && Trip1.tickets > 0) {
                cout << "Train found, here is the information: " << Trip1.route << endl << "Departure time (hours minutes): " << Trip1.time << endl << "class: " << Trip1.t_class << endl << "remaining tickets:" <<  Trip1.tickets << endl;
            }
            else {
                cout << "There is not available train for that city";
            }
        }
        else {
            cout << "Enter name of city you want to go to";
            cin.ignore();
            string city;
            getline(cin, city);
            string temp = Trip1.route;
            if (temp.find(city) == 0 && Trip1.tickets > 0) {
                cout << "Train found, here is the information: " << Trip1.route << endl << "Departure time (hours minutes): " << Trip1.time << endl << "class: " << Trip1.t_class << endl << "remaining tickets:" <<  Trip1.tickets << endl;
                int loop2 = 0;
                while (loop2 == 0) {
                    cout << "would you like to buy a ticket for this train? Y or N: ";
                    
                    string choice2;
                    
                    cin >> choice2;
                    if (choice2 == "Y") {
                        cout << "ticket bought, have a nice day!" << endl;
                        Trip1.tickets -= 1;
                        loop2 = 1;

                    }
                    else if (choice2 == "N") {
                        loop2 = 1;
                    }
            }
        }
        }
    }
}