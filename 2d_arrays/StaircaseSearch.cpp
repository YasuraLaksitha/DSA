//
// Created by ASUS on 06/07/2025.
//

#include <iostream>
#include <vector>

using namespace std;

pair<int, int> staircase_search(const int arr[][4], const int val, const int arrays, const int len) {
    int arr_idx = 0;
    int ele_idx = len - 1;

    while (arr_idx < arrays and ele_idx >= 0) {
        if (arr[arr_idx][ele_idx] > val) ele_idx--;
        else if (arr[arr_idx][ele_idx] < val) arr_idx++;
        else return {arr_idx, ele_idx};
    }
    return {-1, -1};
}

int main() {
    constexpr int arr[][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {27, 29, 37, 48},
        {32, 33, 39, 50}
    };
    constexpr int search_val = 40;

    const auto [fst, snd] = staircase_search(arr, search_val, 4, 4);
    cout << search_val << " is present in [" << fst << "," << snd << "]";
}
