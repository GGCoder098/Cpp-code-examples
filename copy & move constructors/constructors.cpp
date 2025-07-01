#include <iostream>
using namespace std;

class LargeObject {
    int x;
    int y;

public:
    // normal constructor
    LargeObject(const int x, const int y) {
        this->x = x;
        this->y = y;
        cout << "normal constructor" << endl;
    }

    // copy constructor
    LargeObject(const LargeObject &obj) {
        this->x = obj.x;
        this->y = obj.y;
        cout << "copy constructor" << endl;
    }

    // move constructor
    LargeObject(LargeObject &&obj)  noexcept {
        this->x = obj.x;
        this->y = obj.y;
        cout << "move constructor" << endl;
    }

    // move assignment operator
    LargeObject& operator=(LargeObject &&obj) noexcept {
        cout << "move assignment operator" << endl;

        if (this != &obj) {
            this->x = obj.x;
            this->y = obj.y;
        }
        return *this;
    }
};