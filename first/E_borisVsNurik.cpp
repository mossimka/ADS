#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    vector<int> boris;
    vector<int> nursik;
    int n;
    for (int i=0; i<5;i++){
        cin>>n;
        boris.push_back(n);
    }
    for (int i=0; i<5;i++){
        cin>>n;
        nursik.push_back(n);
    }
    int counter = 0;
    long border = pow(10, 6);

    while (!boris.empty() && !nursik.empty()) {
        if (boris[0] == 0 && nursik[0] == 9) {
            boris.push_back(boris[0]);
            boris.push_back(nursik[0]);
        }
        else if (nursik[0] == 0 && boris[0] == 9) {
            nursik.push_back(boris[0]);
            nursik.push_back(nursik[0]);
        }
        else if (boris[0] > nursik[0]) {
            boris.push_back(boris[0]);
            boris.push_back(nursik[0]);
        } else {
            nursik.push_back(boris[0]);
            nursik.push_back(nursik[0]);
        }
        boris.erase(boris.begin());
        nursik.erase(nursik.begin());
        counter++;
        if (counter > border) {
            cout << "blin nichya" << endl;
            return 0;
        }
    }

    if (!boris.empty()) {
        cout << "Boris " << counter << endl;
    } else {
        cout << "Nursik " << counter << endl;
    }

    return 0;
}