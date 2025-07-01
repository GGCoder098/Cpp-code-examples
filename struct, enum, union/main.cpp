#include <iostream>
using namespace std;


union Data {
    int i;
    float f;
    char c;
};


enum Color {
    RED,
    GREEN,
    BLUE
};


enum StatusCode {
    OK = 200,
    NOT_FOUND = 404
};


enum Day {
    SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY
};


class TrafficLight {
public:
    enum LightColor {
        RED,
        YELLOW,
        GREEN
    };

    LightColor currentColor;

    TrafficLight() : currentColor(RED) {}

    void changeLight() {
        if (currentColor == RED)
            currentColor = GREEN;
        else if (currentColor == GREEN)
            currentColor = YELLOW;
        else
            currentColor = RED;
    }

    void display() {
        cout << "Traffic Light is now: ";
        switch (currentColor) {
            case RED: cout << "RED"; break;
            case YELLOW: cout << "YELLOW"; break;
            case GREEN: cout << "GREEN"; break;
        }
        cout << endl;
    }
};


void printColor(Color color) {
    switch (color) {
        case RED: cout << "Color is RED" << endl; break;
        case GREEN: cout << "Color is GREEN" << endl; break;
        case BLUE: cout << "Color is BLUE" << endl; break;
    }
}

int main() {
    // 1.
    Data data;
    data.i = 42;
    cout << "Data as int: " << data.i << endl;
    data.f = 3.14f;
    cout << "Data as float: " << data.f << endl;
    data.c = 'A';
    cout << "Data as char: " << data.c << endl;
    cout << "----" << endl;

    // 2.
    data.i = 100;
    cout << "After setting int to 100:" << endl;
    cout << "int: " << data.i << ", float: " << data.f << ", char: " << data.c << endl;
    cout << "----" << endl;

    // 3.
    Color myColor = GREEN;
    printColor(myColor);
    cout << "----" << endl;

    // 4.
    Day today = WEDNESDAY;
    cout << "Today is day number: " << today << endl;
    cout << "----" << endl;

    // 5.
    StatusCode code = OK;
    cout << "Status code: " << code << endl;
    code = NOT_FOUND;
    cout << "Status code: " << code << endl;
    cout << "----" << endl;

    // 6.
    TrafficLight light;
    light.display();
    light.changeLight();
    light.display();
    light.changeLight();
    light.display();

    return 0;
}
