#include <iostream>
#include <bits/stdc++.h>

using std::cout;
using std::cin;
using std::string;
using std::sort;

bool isAnagram(string, string);

int main() {

    string firstStr;
    string secondStr;

    cout << "Enter the first word: ";
    cin >> firstStr;
    cout << "Enter the second word: ";
    cin >> secondStr;

    cout << isAnagram(firstStr, secondStr);

    return 0;
}

bool isAnagram(string first, string second) {

    int firstLength = first.length();
    int secondLength = second.length();

    if ( firstLength != secondLength) {

        return false;

    } else {

        sort(first.begin(), first.end());
        sort(second.begin(), second.end());

        for (int i = 0; i < firstLength; ++i) {
            if (first[i] != second[i]) {

                return false;
            }
        }
        return true;
    }
}