#include <iostream>
using namespace std;


#define DEBUG
#define LIMIT 10
#define PRINT(x) (cout << x << "\n")
#define SQUARE(x) (x * x)
#define PI 3.14159265359

#define TEST
#undef TEST


int main() {
// cout << TEST;#
    #ifdef PI
        PRINT("PI is defined");
    #elif defined(SQUARE)
        PRINT("SQUARE is defined");
    #else
        PRINT("none are defined");
    #endif


    #ifdef DEBUG
        PRINT("DEBUG MODE ON");
    #endif

    cout << SQUARE(7) << "\n";

    for (int i = 0; i < LIMIT; i++){
        cout << i << "\n";
    }
}
