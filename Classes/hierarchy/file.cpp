#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
#include <random>
using namespace std;

class Device
{
    public:
    string colour;
    string manufacturer;
    bool on = false;
    int size;
    
    void turn_on(){
        on = true;
    }
    void turn_off(){
        on = false;
    }
};

class computer: public Device
{
    string cpu;
    string gpu;
    int storage;
    int power_supply;
    int ram_size;
};

class Monitor: public Device
{
    string resolution;
    int screen_size;
    int refresh_rate;


};

class Laptop: public Device, public computer, public Monitor
{

};