/*
You are defending a kingdom represented as a 2D grid of size W x H.
Enemies have placed watchtowers at certain coordinates on this grid.
Each watchtower can monitor its entire row and column, preventing defense
placement there.

Your task is to find the largest rectangular area on the grid that is *not* monitored by any watchtower.
You are given a list of the coordinates (x, y) of the watchtowers.

Write a function that
returns the area of the largest such rectangle.

Constraints:
- 1 ≤ W, H ≤ 10^5
- 0 ≤ number of watchtowers ≤ 10^4
- 1 ≤ x ≤ W, 1 ≤ y ≤ H (watchtower positions)

Expected Time Complexity: O(N log N)

Example:
Input:
W = 15, H = 8
position = {{3, 8}, {11, 2}, {8, 6}}

Output:
12

Explanation:
The largest safe area is a 4 x 3 rectangle (width = max gap between columns - 1, height = max gap between rows - 1).
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int find_area(vector<pair<int, int>> t, int w, int h)
{
    vector<int> x, y;

    x.push_back(0);
    y.push_back(0);

    for (int i = 0; i < t.size(); i++)
    {
        x.push_back(t[i].first);
        y.push_back(t[i].second);
    }

    x.push_back(w + 1);
    y.push_back(h + 1);

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int max_gap_x = INT_MIN;
    int max_gap_y = INT_MIN;

    for (int i = 0; i < x.size() - 1; i++)
    {
        max_gap_x = max((x[i + 1] - x[i] - 1), max_gap_x);
        max_gap_y = max((y[i + 1] - y[i] - 1), max_gap_y);
    }

    return max_gap_x * max_gap_y;
}

int main()
{
    vector<pair<int, int>> towerts = {{3, 8}, {11, 2}, {8, 6}};
    int W = 15, H = 8;

    cout << "Area: " << find_area(towerts, W, H);
    return 0;
}