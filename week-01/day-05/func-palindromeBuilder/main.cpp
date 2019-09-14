#include <iostream>
#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::string;
using std::sort;
using std::endl;

string createPalindrome(string, bool&);

int main() {

    string input;
    cout << "Enter a string: ";
    cin >> input;

    bool flag;

    cout << createPalindrome(input, flag) << endl;

    flag ? cout << "It is a palindrome." : cout << "I turned it into a palindrome.";

    return 0;
}

string createPalindrome(string inputText, bool& flag) {

    int len = inputText.length();
    string reverse;

    for (int i = 1; i <= len; ++i) {
        reverse += inputText[len - i];
    }

    for (int j = 0; j < len; ++j) {
        if (reverse[j] != inputText[j]) {
            flag = false;                   // false if we have to change the text
            return inputText + reverse;
        }
    }

    flag = true;                            // true if it was a palindrome to begin with
    return inputText;

}