//
// Created by ASUS on 11/07/2025.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int calculate_total_marks(const vector<int> &marks) {
    int total_marks = marks[0];

    for (int i = 0; i < marks.size(); i++) {
        total_marks += marks[0];
    }

    return total_marks;
}

bool compare(const pair<string, vector<int> > &s1, const pair<string, vector<int> > &s2) {
    return calculate_total_marks(s1.second) > calculate_total_marks(s2.second);
}

int main() {
    vector<pair<string, vector<int> > > student_marks = {
        {"Kamal", {10, 20, 30}},
        {"Amal", {50, 70, 30}},
        {"Sunil", {60, 80, 40}},
    };

    sort(student_marks.begin(), student_marks.end(), compare);

    for (auto [fst,snd]: student_marks) {
        cout << fst << ":" << snd[0] << endl;
    }
}
