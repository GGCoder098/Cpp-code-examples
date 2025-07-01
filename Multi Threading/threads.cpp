#include <algorithm>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;

mutex vector_lock;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    if (n <= 3) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }


    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}


void primes_in_range(int min, int max, vector<int> &primes, int& n) {
    for (int i = min; i <= max; i++) {
        if (isPrime(i)) {
            unique_lock<mutex> lock(vector_lock);
            primes.push_back(i);
            lock.unlock();
        }
    }
    unique_lock<mutex> lock(vector_lock);
    n++;
    lock.unlock();
}

int main() {
    vector<int> primes;
    int min = 0;
    int n = 0;
    int max = 100;
    int split = max / 8;
    for (int i = 0; i < 8; i++) {
        new thread(primes_in_range, split*i, split*(i+1), ref(primes), ref(n));
    }

    while (true) {
        if (n == 8) {
            sort(primes.begin(), primes.end());
            for (auto x: primes) {
                cout << x << " ";
            }
            break;
        }
    }
    return 0;
}
