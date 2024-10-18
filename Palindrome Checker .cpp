#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindromeIterative(const string &str) {
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false; // Not a palindrome
        }
        left++;
        right--;
    }
    return true; 
}

bool isPalindromeRecursive(const string &str, int left, int right) {
    if (left >= right) {
        return true; 
    }
    if (str[left] != str[right]) {
        return false; 
    }
    return isPalindromeRecursive(str, left + 1, right - 1); 
}

int main() {
    string input;

    cout << "Enter a string: ";
    getline(cin, input);


    string filteredInput;
    for (char c : input) {
        if (isalnum(c)) {
            filteredInput += tolower(c); // Convert to lowercase
        }
    }
    bool iterativeResult = isPalindromeIterative(filteredInput);
    cout << "Iterative: The string \"" << input << "\" is " << (iterativeResult ? "a palindrome." : "not a palindrome.") << endl;

    bool recursiveResult = isPalindromeRecursive(filteredInput, 0, filteredInput.length() - 1);
    cout << "Recursive: The string \"" << input << "\" is " << (recursiveResult ? "a palindrome." : "not a palindrome.") << endl;

    return 0;
}
