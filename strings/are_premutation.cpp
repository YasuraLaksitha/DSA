/*
    Problem Statement:
    ------------------
    Given two strings `str1` and `str2`, write a function `arePermutation` that checks whether one string
    is a permutation of the other.

    Two strings are said to be permutations of each other if they contain the same characters,
    only the order of characters can be different.

    Constraints:
    ------------
    - The function should be case sensitive.
    - Assume the input strings contain only ASCII characters.
    - Try to achieve a time complexity of O(N log N) or better.

    Function Signature:
    -------------------
    bool arePermutation(string str1, string str2);

    Example:
    --------
    Input: str1 = "listen", str2 = "silent"
    Output: true

    Input: str1 = "triangle", str2 = "integral"
    Output: true

    Input: str1 = "apple", str2 = "pale"
    Output: false
*/

#include <bits/stdc++.h>
using namespace std;

bool check_premutation(string str1, string str2)
{
    if (str1.length() != str2.length())
        return false;

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}

int main()
{
    const string str1 = "abc";
    const string str2 = "bac";

    cout << str2 << " is " << (check_premutation(str1, str2) ? "a " : "not a ") << "pre mutation of " << str1;
    return 0;
}
