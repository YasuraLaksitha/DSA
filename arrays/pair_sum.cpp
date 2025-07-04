//
// Created by ASUS on 01/05/2025.
//

#include "pair_sum.h"

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

pair<int,int> pair_sum::find_pair(vector<int> v, int val) {
    int l_ele = 0, r_ele = 0;
    int lp = 0, rp = v.size() - 1, diff = INT_MAX;

    while (lp < rp) {
        if (abs(v[lp] + v[rp] - val) < diff) {
            l_ele = lp;
            r_ele = rp;
            diff = abs(v[lp] + v[rp] - val);
        }

        if (abs(v[lp] + v[rp]) > val) {
            rp--;
        } else {
            lp++;
        }
    }
    return {v[l_ele], v[r_ele]};
}

int main() {
    vector<int> arr = {5, 12, 17, 23, 38, 45, 57, 63, 79, 81};
    int x = 100;

    pair<int, int> pair = pair_sum::find_pair(arr, x);

    cout << pair.first << "," << pair.second;
    return 0;
}
