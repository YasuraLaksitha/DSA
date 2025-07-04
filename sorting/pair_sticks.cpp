/*
You are given an array `length` of N stick lengths and an integer D.
Your task is to form as many pairs of sticks as possible such that
the absolute difference between the lengths of each pair is less than or equal to D.

Each stick can be used in at most one pair.

Write a function that returns the maximum number of such valid pairs.

Expected Time Complexity: O(N log N)
Expected Auxiliary Space: O(1)

Example:
Input: length = {1, 3, 3, 9, 4}, D = 2
Output: 2
Explanation: You can pair (1, 3) and (3, 4). 9 is left unpaired.
*/

#include <iostream>
#include <vector>
using namespace std;

void insertion_sort(vector<int>& a)
{
    for (int i = 0; i < a.size(); i++)
    {
        int current = a[i];
        int pre_pos = i - 1;

        while (pre_pos >= 0 and a[pre_pos] > current)
        {
            a[pre_pos + 1] = a[pre_pos];
            pre_pos--;
        }
        a[pre_pos + 1] = current;
    }
}

vector<pair<int, int>> find_pairs(vector<int> a, int D)
{
    vector<pair<int, int>> pairs;

    for (int i = 0; i < a.size() - 1; i++)
    {
        if (a[i + 1] - a[i] <= D)
        {
            pairs.push_back({a[i + 1], a[i]});
            i++;
        }
    }
    return pairs;
}

int main()
{
    vector<int> arr = {1, 3, 3, 9, 4};
    int D = 2;

    insertion_sort(arr);
    vector<pair<int, int>> pairs = find_pairs(arr, D);

    for (auto x : pairs)
    {
        cout << x.first << "," << x.second << endl;
    }
    return 0;
}
