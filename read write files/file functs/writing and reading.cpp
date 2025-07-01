#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
using namespace std;


int read(string name) {
    string line;
    ifstream myfile(name);
    if(!myfile) {
        cout << "Error: Unable to open the file." << endl;
        return 1; 
    }


    while (!myfile.eof()){
        getline(myfile, line);
        cout << line << endl;
    }
    string choice;
    
    cout << "add ints y or n: ";
    getline(cin, choice);
    int total = 0;
    int x;
    myfile.clear();
    myfile.seekg(0, ios::beg);
    if (choice == "y") {
        while (myfile >> x) {
            total = total + x;

        }
    }
    cout << total;

    int min = 99999999;
    myfile.clear();
    myfile.seekg(0, ios::beg);
    
    cout << "find smallest int? y or n:  ";
    getline(cin, choice);
    if (choice == "y") {
        while (myfile >> x) {
            if (x < min) {
                min = x;
            }

        }

    }
    cout << min << endl;
    




    
    return 0;

}

int write(string line, string name) {
    ofstream myfile(name);
    myfile << line << endl;
    return 0;

}




int main() {
    int x = 0;
    string name;
    string line;
    cout << "enter name of file: ";
    getline(cin, name);
    cout << "enter 1 to read or 2 to write: ";
    cin >> x;
    cin.ignore();
    

    if (x == 1) {
        read(name);

    } 
    else {
        cout << "enter what you want to write: ";
        getline(cin, line);
        write(line, name);
    }
    
    
    
    
    
    return 0;
}