//
// Created by ASUS on 05/07/2025.
//

/*
 * Problem Statement:
 * Implement a function that takes a string as input and returns its run-length encoded form.
 * The encoding should count the frequency of each character in the string and represent
 * consecutive characters by the character followed by its count (if greater than 1).
 *
 * For example:
 * Input:  "aaabbc"
 * Output: "a3b2c"
 *
 * Note:
 * - The order of characters in the output should follow their order of appearance in the input.
 * - If a character appears only once consecutively, the count should be omitted.
 * - Assume the input string contains only ASCII characters.
 */

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

static string compress(const string &s) {
    map<char, int> freq;

    // Add the chars into map with the correct frequency
    for (char c: s)
        freq[c]++;

    string encoded;

    //create the compressed string
    for (auto [fst, snd]: freq) {
        encoded += fst;

        if (snd > 1)
            encoded += to_string(snd);
    }

    return encoded;
}


int main() {
    const string str = "aabbbcdde";

    cout << str << "->Encoded: " << compress(str);
}
