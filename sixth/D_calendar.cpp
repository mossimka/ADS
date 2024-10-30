#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    bool is_greater_than(Date other) {
        if (this->year > other.year) return true;
        if (this->year < other.year) return false;
        if (this->month > other.month) return true;
        if (this->month < other.month) return false;
        if (this->day > other.day) return true;
        return false;
    }
};

// Partition function for QuickSort
int partition(vector<Date>& vec, int start, int end) {
    int p = start + rand() % (end - start + 1);
    swap(vec[p], vec[start]);
    Date x = vec[start];
    int l = start + 1, r = end;
    
    while (l <= r) {
        if (x.is_greater_than(vec[l])) {
            l++;
        } else {
            swap(vec[l], vec[r]);
            r--;
        }
    }
    swap(vec[start], vec[r]);
    return r;
}

// QuickSort function
void quick_sort(vector<Date>& vec, int start, int end) {
    if (start >= end) {
        return;
    }
    int p = partition(vec, start, end);
    quick_sort(vec, start, p - 1); 
    quick_sort(vec, p + 1, end);
}

int main() {
    int n;
    cin >> n;
    vector<Date> dates;
    for (int i = 0; i < n; ++i) {
        string str_date;
        cin >> str_date;
        int day = stoi(str_date.substr(0, 2));
        int month = stoi(str_date.substr(3, 2));
        int year = stoi(str_date.substr(6, 4));
        dates.push_back(Date(day, month, year));
    }
    quick_sort(dates, 0, n - 1);

    for (const Date& date : dates) {
        cout << (date.day < 10 ? "0" : "") << date.day << '-'
             << (date.month < 10 ? "0" : "") << date.month << '-'
             << date.year << endl;
    }

    return 0;
}
