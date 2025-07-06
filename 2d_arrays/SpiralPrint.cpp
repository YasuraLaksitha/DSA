//
// Created by ASUS on 06/07/2025.
//

/*
 * Problem Statement:
 *
 * Given a 2D matrix of size M x N (in this case, 4 x 4),
 * print the elements of the matrix in spiral order.
 *
 * Spiral order means:
 * - Start from the top-left element.
 * - Traverse the first row from left to right,
 * - Then the last column from top to bottom,
 * - Then the last row from right to left,
 * - Then the first column from bottom to top,
 * - Continue inward in this pattern until all elements are printed.
 *
 * Input:
 * A statically defined 2D array with M rows and N columns.
 *
 * Output:
 * Print all elements in spiral order, separated by spaces.
 *
 * Example:
 * Input matrix:
 *  1   2   3   4
 * 12  13  14   5
 * 11  16  15   6
 * 10   9   8   7
 *
 * Output:
 * 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
 */

#include <iostream>
using namespace std;

void spiral_print_array(const int arr[][4], const int arrays, const int len) {
    int start_ele_idx = 0;
    int end_ele_idx = len - 1;
    int start_arr_idx = 0;
    int end_arr_idx = arrays - 1;

    while (start_arr_idx <=end_arr_idx) {
        for (int i = start_ele_idx; i <= end_ele_idx; i++) {
            cout << arr[start_arr_idx][i] << " ";
        }

        for (int i = start_arr_idx + 1; i <= end_arr_idx; i++) {
            cout << arr[i][end_ele_idx] << " ";
        }

        for (int i = end_ele_idx - 1; i >= start_ele_idx; i--) {
            cout << arr[end_arr_idx][i] << " ";
        }

        for (int i = end_arr_idx - 1; i > start_arr_idx; i--) {
            cout << arr[i][start_ele_idx] << " ";
        }

        start_ele_idx++;
        end_ele_idx--;
        start_arr_idx++;
        end_arr_idx--;
    }
}

int main() {
    constexpr int m = 4;
    constexpr int n = 4;
    constexpr int arr[][4] = {
        {1, 2, 3, 4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10, 9, 8, 7}
    };

    spiral_print_array(arr, n, m);
}
