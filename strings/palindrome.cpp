#include <iostream>
#include <cstring>
using namespace std;

bool check_palindrome(string str)
{
    int len = str.length() - 1;

    int i = 0;
    while (len >= 0)
    {
        if (str[i] != str[len--])
        {
            return false;
        }
        i++;
    }
    return true;
}

int main()
{
    char word[100];
    cin.getline(word, 100);
    string str(word);

    cout << "The string is " << (check_palindrome(str) ? "a palindrome" : "not a palindrome");
}