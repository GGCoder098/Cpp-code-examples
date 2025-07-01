#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

// ostream &temp(ostream &output) {
//     cout << fixed << setprecision(4) << setfill('\\') << setw(10);
//     return output;
// }
//
// float toFahrenheit(const float celsius) {
//     return static_cast<float>(32.0 + 1.8 * celsius);
// }
//
// // float toCelsius(const float fahrenheit) {
// //     return static_cast<float>((fahrenheit - 32.0) / 1.8);
// // }
//
// float toKelvin(const float celsius) {
//     return static_cast<float>(celsius + 273.15);
// }
// int main() {
//     float cel = 20.0;
//     float fahrenheit = toFahrenheit(cel);
//     cout << temp << fahrenheit << endl;
//     cout << temp << toKelvin(cel) << endl;
// }

ostream &table(ostream &output) {

    cout << setw(5) << "|" << setw(5);
    return output;
}

void make_table(vector<vector<string>> &table) {
    vector<int> col_widths;
    int max = 0;
    int length = 0;
    for (const vector<string>& row : table) {
        for (const string& col : row) {
            if (col.length() > max) {
                max = static_cast<int>(col.length());
            }
        }
        col_widths.push_back(max);
    }

    for (const auto & i : table) {
        for (int j = 0; j < i.size(); j++) {
            cout << left << "|" << setw(col_widths[j] + 2) << i[j];
            length += static_cast<int>(col_widths[j] + 3);
        }
        cout << "|" << endl << "-";
        cout << setw(length) << setfill('-') << "" << endl;
        cout << setfill(' ');
        length = 0;
    }

}

int main() {
    vector<vector<string>> table = {{"abcawdawd", "cba", "cba"}, {"cba", "abc", "cba"} };
    make_table(table);
    // string input;
    // getline(cin, input);
    // for (const auto i: input) {
    //     cout << table <<static_cast<char>(tolower(i)) << table;
    //     cout << " octal code: " << oct << static_cast<int>(i);
    //     cout << " hex code: " << hex << static_cast<int>(i);
    //     cout << endl;
    // }
}
