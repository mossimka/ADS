#include <iostream>
#include <map>
#include <vector>
#include <iomanip> 

using namespace std;

map<string, double> grade = {
    {"A+", 4.00}, {"A", 3.75}, {"B+", 3.50}, {"B", 3.00}, 
    {"C+", 2.50}, {"C", 2.00}, {"D+", 1.50}, {"D", 1.00}, {"F", 0.00}
};

class Student {
public:
    string name;
    double gpa;   

    Student(string name, vector<pair<string, int>> grades) {
        this->name = name;
        int total_credits = 0;
        double total_points = 0;
        for (const auto& grade_info : grades) {
            string grade_letter = grade_info.first;
            int credits = grade_info.second;
            total_credits += credits;
            total_points += grade[grade_letter] * credits;
        }
        this->gpa = total_points / total_credits;
    }
};


int partition(vector<Student>& vec, int start, int end) {
    int p = start + rand() % (end - start + 1);
    swap(vec[start], vec[p]);
    Student x = vec[start];
    int l = start + 1, r = end;
    
    while (l <= r) {
        if (x.gpa > vec[l].gpa || (x.gpa == vec[l].gpa && x.name > vec[l].name)) {
            l++;
        } else {
            swap(vec[l], vec[r]);
            r--;
        }
    }
    swap(vec[start], vec[r]);
    return r;
}

void quick_sort(vector<Student>& vec, int start, int end) {
    if (start >= end) return;
    int p = partition(vec, start, end);
    quick_sort(vec, start, p - 1);
    quick_sort(vec, p + 1, end);
}


int main() {
    int n;
    cin >> n;
    vector<Student> students;
    for (int i = 0; i < n; ++i) {
        string name, lastname;
        cin >> name >> lastname;
        name += (" " + lastname);
        int m;
        cin >> m;
        vector<pair<string, int>> grades;
        for (int j = 0; j < m; ++j) {
            string grade_letter;
            int credits;
            cin >> grade_letter >> credits;
            grades.push_back({grade_letter, credits});
        }
        students.push_back(Student(name, grades));
    }

    quick_sort(students, 0, n - 1);

    for (Student student : students) {
        cout << fixed << setprecision(3) << student.name  << ' ' << student.gpa << endl;
    }
    
    return 0;
}