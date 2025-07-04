//
// Created by ASUS on 01/05/2025.
//

/*
 * Problem: K-Rotate an Array (Right Rotation)
 * -------------------------------------------
 * Given an array 'a' of size 'n' and an integer 'k', rotate the array to the right by 'k' positions.
 * Elements that move past the end of the array should wrap around to the beginning.
 *
 * Example:
 * Input:
 *   a = [1, 2, 3, 4, 5]
 *   k = 2
 * Output:
 *   [4, 5, 1, 2, 3]
 *
 * Constraints:
 *   - 1 <= n <= 10^6
 *   - 0 <= k <= 10^9
 *
 * Expected Time Complexity: O(n)
 * Expected Auxiliary Space: O(n)
 */


#ifndef K_ROTATE_H
#define K_ROTATE_H
#include<iostream>
#include <vector>
using namespace std;

class k_rotate {
public:
    static vector<int> rotate(vector<int> v ,int key);
};

#endif //K_ROTATE_H
