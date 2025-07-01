#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int result = 0;
    bool wasNum = false;
    vector<double> nums = {1, 2};
    vector<string> operators = {"+"};
    int DecimalP = 1;
    // for(int i = 0; i < nums.size(); i++) {
    //     cout << nums[i] << endl;
    // }
    nums[nums.size()-1] = nums[nums.size()-1] + 3 * pow(10, -DecimalP);
    cout << nums[nums.size()-1] << endl;
}
