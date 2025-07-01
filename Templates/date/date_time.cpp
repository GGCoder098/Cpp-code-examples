#include <iostream>  
#include <vector>
#include <algorithm>
using namespace std;  
    
    
template <class t>
class DateTime {    
        public:
        void setDate(t d, t m, t y){
            day = d;
            month = m;
            year = y;

        }
        void NewYear(){
            int days = 365;
            for (int i = 0; i < month-1; i++){
                days -= months[i];
            }
            days-=day;
            cout << days << endl;
        }
        void print(){
            cout << day << "/" << month << "/" << year << endl;
        }

        bool operator!=(DateTime<t> const &x){
            if (x.day == day && x.month == month && x.year == year){
                return false;
            }
            else{
                return true;
            }
        }
        DateTime<t> operator-(DateTime<t> const &x){
            DateTime<t> interval;
            interval.day = day - x.day;
            interval.month = month - x.month;
            interval.year = year - x.year;
            if (interval.day<0){
                interval.day = day*-1;
            }
            if (interval.month<0){
                interval.month = month*-1;
            }
            if (interval.year<0){
                interval.year = year*-1;
            }
            return interval;
            
        }
        private:
        int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        t day;
        t month;
        t year;
    
};
int main(){
    DateTime<int> x;
    DateTime<int> y;
    x.setDate(25,1,2025);
    x.print();
    x.NewYear();
    y.setDate(25,1,2025);
    if (x!=y){
        cout << "false";
    }
    DateTime<int> new_date;
    new_date = x-y;
    new_date.print();
    return 0;
}