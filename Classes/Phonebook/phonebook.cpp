#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
using namespace std;

class contact
{
public:
    string contact_name;

    void print_home_number(){
        cout << home_number << endl;
    }
    void print_mobile_number(){
        cout << mobile_number << endl;
    }
    void input_number() {
        cout << "input number: ";
        getline(cin, mobile_number);
    }
    void show_contact_name(){
        cout << contact_name << endl;
    }
private:
    string mobile_number;
    string home_number;

};


int main() {

}