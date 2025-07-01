#include <iostream>
using namespace std;

namespace MathFuncs {
    int add(int x, int y) {
        return x + y;
    }
    int subtract(int x, int y) {
        return x - y;
    }

}
namespace Greetings {
    void sayHello() {
        cout << "Hello World!" << endl;
    }
}

namespace VeryLongNamespaceName {
    void printMessage(string x) {
        cout << x << endl;
    }
}

namespace Company {
    namespace HR {
        void hireEmployee() {
            cout << "Employee Hired" << endl;
        }
    }
}

namespace {
    void print() {
        cout << "Hello World!" << endl;
    }
}

int main() {
    print();
    using Greetings::sayHello;
    namespace n = VeryLongNamespaceName;
    int x = MathFuncs::add(1, 2);
    int y = MathFuncs::subtract(2, 1);
    sayHello();
    n::printMessage("Hello!");
    Company::HR::hireEmployee();

}