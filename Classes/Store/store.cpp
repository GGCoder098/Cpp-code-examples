#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
#include <random>
using namespace std;

class product
{
    public:
        string name;
        int price;

};

class laptop : public product
{
    public:
        void set_data(string input, int price) {
            name = "laptop";
            this->price = price;
            manufacturer = input;
        }
        void get_data() {
            cout << "Product: " << name << endl
                 << "Price: $" << price << endl
                 << "Manufacturer: " << manufacturer << endl;
        }
    private:
        string manufacturer;

};

class table
{
    public:
    product info;
        void set_data(int price) {
            info.name = "Table";
            info.price = price;
            
        }
        void get_data() {
            cout << "Product: " << info.name << endl
                 << "Price: $" << info.price << endl;
        }
        
    private:
        

        
};


int main(){
    laptop laptop;
    table table;
    laptop.set_data("Asus", 1300);
    table.set_data(50);
    laptop.get_data();
    cout << endl;
    table.get_data();

}