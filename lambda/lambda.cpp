#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class User {
public:
    string name;
    int age;

    User(string name, int age) : name(name), age(age) {}


    void print() const {
        cout << name << " (" << age << ")\n";
    }
};


template <typename item, typename lambda>
void sortContainer(item& container, lambda comp) {
    sort(container.begin(), container.end(), comp);
}


int main() {
    vector<User> users = {
        User("Alice", 30),
        User("Bob", 25),
        User("Charlie", 35)
    };

    cout << "Before sorting:\n";
    for (const auto& user : users) user.print();

    sortContainer(users, [](const User& a, const User& b) {
        return a.age < b.age;
    });

    cout << "\nAfter sorting by age:\n";
    for (const auto& user : users) user.print();

    return 0;
}
