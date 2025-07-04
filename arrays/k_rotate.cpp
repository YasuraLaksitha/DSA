//
// Created by ASUS on 01/05/2025.
//

/*
   🔁 Question: Rotate an Array by K Positions

   Given an array of integers 'a' and an integer 'k', rotate the array to the right by 'k' positions.

   Example:
   Input:  a = [1, 2, 3, 4, 5], k = 2
   Output: [4, 5, 1, 2, 3]

   Constraints:
   - Time Complexity: O(n)
   - Space Complexity: O(n) or O(1) depending on implementation
   - Note: You must handle cases where k > size of array
*/

#include "k_rotate.h"
#include<vector>
#include <initializer_list>
#include <iostream>
using namespace std;

vector<int> k_rotate::rotate(vector<int> a, int k) {
    vector<int> v;
    int n = a.size();
    k = k % n;

    for (int i = 0; i < n; i++) {
        if (i < k) {
            v.push_back(a[n + i - k]);
        } else {
            v.push_back(a[i - k]);
        }
    }
    return v;
}


int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    int k = 2;

    vector<int> res = k_rotate::rotate(v, k);

    for (int val : res)
        cout << val << " ";
    cout << endl;

    return 0;
}
