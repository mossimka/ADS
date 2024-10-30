#include <iostream>
#include <vector>

using namespace std;

bool less_than(const string& s1, const string& s2) {
    return s1.size() < s2.size();
}

void merge(vector<string>& vec, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);
    for (int i = 0; i < n1; ++i) {
        L[i] = vec[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = vec[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (less_than(L[i], R[j]) || (L[i].size() == R[j].size())) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vec[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vec[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(vector<string>& vec, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);
    merge(vec, left, mid, right);
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    vector<vector<string>> vecs(n);
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        string word = "";
        for (char ch : line) {
            if (ch == ' ') {
                if (!word.empty()) {
                    vecs[i].push_back(word);
                    word = "";
                }
            } else {
                word += ch;
            }
        }

        if (!word.empty()) {
            vecs[i].push_back(word);
        }
    }

    for (int i = 0; i < n; ++i) {
        merge_sort(vecs[i], 0, vecs[i].size() - 1);
    }

    for (vector<string> vec : vecs) {
        for (string word : vec) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}
