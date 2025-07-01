#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
#include <random>
using namespace std;

class Time
{
    public:
    int time;
    void enter_time(string time2){
        time = stoi(time2);
    }
};



class Train
{
    Time departure;
    Time arrival;
    string city_start;
    string city_destination;
    int tickets_amount;
    string train_class;
    public:

    void load_data(){
        ifstream info("info.txt");
        string line;
        for (int i = 0; i < 6; i++) {
            if (i == 0) {
                getline(info, line);
                departure.enter_time(line);
            }
            else if (i == 1) {
                getline(info, line);
                arrival.enter_time(line);
            }
            else if (i == 2) {
                getline(info, line);
                city_start = line;
            }
            else if (i == 3){
                getline(info, line);
                city_destination = line;
            }
            else if (i == 4){
                getline(info, line);
                tickets_amount = stoi(line);
            }
            else if (i == 4){
                getline(info, line);
                train_class = line;
            }

        }
    }

    void count_time(){
        cout << "The train journey is " << (departure.time - arrival.time)/ 1000 << " hours long" <<endl;
    }

    bool can_buy_ticket(){
        if (tickets_amount == 0) {
            return false;
        }
        else{
            return true;
        }
    }
    
    void buy_ticket(){
        if (can_buy_ticket() == true){
            tickets_amount -= 1;
        }
        else{
            cout << "no tickets left" << endl;
        }
    }

    void return_ticket(int current_time){
        if (departure.time - current_time < 1000){
            cout << "cannot return ticket" << endl;
        }
        else{
            cout << "ticket returned" << endl;
            tickets_amount += 1;
        }
    }


};



int main(){

    Train var;
    var.load_data();




}







  
    
