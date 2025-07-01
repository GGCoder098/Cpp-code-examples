#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
#include <random>
using namespace std;

class Animals
{
    private:
        bool eat_people;
        
    public:
        void set_bite(){
            eat_people = rand() % 2 == 1;
        }
        void check_bite(){
            if (eat_people == true){
                cout << "Hurry up! Run!" << endl;
            }
            else{
                cout << "You're lucky, it doesn't bite" << endl;
            }
        }
};


int main(){
    time_t seconds;
    time(&seconds);
    srand((unsigned int) seconds);
    Animals animal1;
    Animals animal2;
    Animals animal3;
    animal1.set_bite();
    animal2.set_bite();
    animal3.set_bite();
    vector <Animals> animals = {animal1, animal2, animal3};
    cout << "Choose cage 1 2 or 3: ";
    int cage;
    cin >> cage;
    animals[cage - 1].check_bite();

    




}