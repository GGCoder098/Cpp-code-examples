#include <iostream>  
#include <ctime>  
#include <vector>  
#include <string>
#include <array>
#include <fstream>
#include <algorithm>
#include <random>
using namespace std;



class shape {
public:
  virtual void area() = 0;
  virtual void perimiter() = 0;
};

class triangle: public shape {
    public:
    float height;
    float base;
    float side1;
    float side2;
    float side3;

    triangle() {
        cout << "height, base, side1, 2, 3: ";
        cin >> this->height;
        cin >> this->base;
        cin >> this->side1;
        cin >> this->side2;
        cin >> this->side3;
    }


    void area() {
        cout << (this->height/2) * this->base << endl;
    }
    void perimiter() {
        cout << this->side1 + this->side2 + this->side3 << endl;
    }
};


class square: public shape {
    public:
    float side;

    square(){
        cout << "side: ";
        cin >> this->side;
    }

    void area() {
        cout << this->side * this->side << endl;
    }
    void perimiter() {
        cout << this->side * 4 << endl;
    }
};



class trapeze: public shape {
    public:
    float height;
    float bottom;
    float top;
    float side1;
    float side2;

    trapeze(){
        cout << "height, bottom, top, left side, right side: ";
        cin >> this-> height;
        cin >> this-> bottom;
        cin >> this-> top;
        cin >> this-> side1;
        cin >> this-> side2;
    }


    void area() {
        cout << ((this->bottom + this->top) / 2) * this->height << endl;
    }
    void perimiter() {
        cout << this->bottom + this->top + this->side1 + this->side2 << endl;
    }
};





class circle: public shape {
    public:
    float radius;

    circle(){
        cout << "radius: ";
        cin >> this->radius;
    }

    void area() {
        cout << (this->radius * this->radius) * 3.14159 << endl;
    }
    void perimiter() {
        cout << (this->radius * 2) * 3.14159 << endl;
    }
};

int main() {
    circle c;
    trapeze t;
    square s;
    triangle tr;
    c.area();
    c.perimiter();
    t.area();
    t.perimiter();
    s.area();
    s.perimiter();
    tr.area();
    tr.perimiter();

}
