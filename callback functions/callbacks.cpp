#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <functional>
using namespace std;

// //1.
// void executeCallback(void (*callback)()) {
//         callback();
// }
// void myCallback() {
//     cout << "Hello from callback!" << std::endl;
// }
//
// //2.
// void performOperation(int a, int b, int (*op)(int, int)) {
//     cout << op(a, b) << endl;
// }
// int add(int a, int b) {
//     return a + b;
// }
//
// //3.
// bool compare(int a, int b) {
//     return a > b;
// }
//
// int main() {
//     executeCallback(myCallback);
//
//     performOperation(10, 20, add);
//
//     vector<int> v = {1, 2, 3, 4, 5};
//     sort(v.begin(), v.end(), compare);
//     for (int i : v) {
//         cout << i << endl;
//     }
//     return 0;
// }


//1.
// void buttonClicked() {
//     cout << "Button clicked!" << endl;
// }
//
// void clickButton(bool &clicked) {
//     clicked = true;
// }
//
// void setOnClickListener(void (*callback)(), const bool &clicked) {
//     while (!clicked) {
//         // Sleep a bit to prevent high CPU usage
//         this_thread::sleep_for(chrono::milliseconds(100));
//     }
//     callback();
// }
//
// int main() {
//     bool clicked = false;
//
//
//     thread listenerThread(setOnClickListener, buttonClicked, ref(clicked));
//
//
//     this_thread::sleep_for(chrono::seconds(1));
//     clickButton(clicked);
//     listenerThread.join();
//     return 0;
// }


//2.
// void executeWithCallback(std::function<void()> callback, int numTimes = 1) {
//     for (int i = 0; i < numTimes; ++i) {
//         callback();
//     }
// }
//
// int main() {
//     int counter = 0;
//
//     auto incrementCounter = [&counter]() {counter++;};
//
//     executeWithCallback(incrementCounter, 3);
//
//     std::cout << "\nFinal counter value: " << counter << std::endl;
//
//     return 0;
// }

// 3.

class Notifier {
    private:
        vector<function<void()>> callbacks;
    public:
        void addCallback(function<void()> callback) {
            callbacks.push_back(callback);
        }

        void notify() {
            for (auto callback : callbacks) {
                callback();
            }
        }
};

int main() {
    Notifier notifier;
    notifier.addCallback([]() {cout << "Hello from callback 1!" << endl;});
    notifier.addCallback([]() {cout << "Hello from callback 2!" << endl;});
    notifier.addCallback([]() {cout << "Hello from callback 3!" << endl;});
    notifier.notify();
    return 0;
}