#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
using namespace std;


class calc
{
public:
    void set_nums() {
        int first;
        int second;
        cout << "enter the two numbers" << endl;
        cin >> first >> second;
        
        num1 = first;
        num2 = second;
    }
    void print() {
        cout << total << endl;
    }
    double mult() {
        total = num1 * num2;
        return total;
    }
    double div() {
        total = num1 / num2;
        return total;
    }
    double add() {
        total = num1 + num2;
        return total;
    }
    double sub() {
        total = num1 - num2;
        return total;
    }
    
private:
    double num1;
    double num2;
    double total;

};

int main() {
    calc nums;
    nums.set_nums();
    int choice;
    bool loop = true;
    cout << "1. mult" << endl << "2. div" << endl << "3. add" << endl << "4. sub" << endl;
    while (loop == true) {
        cin >> choice;
        if (choice == 1) {
            nums.mult();
        }
        else if (choice == 2) {
            nums.div();
        }
        else if (choice == 3) {
            nums.add();
        }
        else if (choice == 4) {
            nums.sub();
        }
        nums.print();
    }


}