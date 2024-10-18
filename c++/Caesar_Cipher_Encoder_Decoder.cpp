#include <iostream>
#include <string>

using namespace std;

void decode() {
    string in_str;
    cout << "Enter the string to decode: ";
    cin.ignore(); // To clear the newline character left in the buffer
    getline(cin, in_str); // Using getline to capture full string including spaces
    bool isKey = false;
    char check;
    cout << "Do you have a key?(Y/n): ";
    cin >> check;
    if (check == 'y' || check == 'Y') isKey = true;
    
    if (isKey) {
        long long key;
        cout << "Enter key for decryption: ";
        cin >> key;
        key = key % 26; // Adjust key to be within the 26 alphabet range
        if (key < 0) {
            cout << "Key has to be positive!" << endl;
            return;
        }
        
        string str = in_str;
        for (long long i = 0; i < (long long)str.length(); i++) {
            if (isupper(str[i])) {
                str[i] = ((str[i] - 'A' - key + 26) % 26) + 'A';
            } else if (islower(str[i])) {
                str[i] = ((str[i] - 'a' - key + 26) % 26) + 'a';
            }
        }
        cout << "Decoded string: " << str << endl;
    } else {
        cout << "Bruteforcing all 26 combinations..." << endl;
        for (int key = 0; key < 26; key++) {
            string str = in_str;
            for (long long i = 0; i < (long long)str.length(); i++) {
                if (isupper(str[i])) {
                    str[i] = ((str[i] - 'A' - key + 26) % 26) + 'A';
                } else if (islower(str[i])) {
                    str[i] = ((str[i] - 'a' - key + 26) % 26) + 'a';
                }
            }
            cout << "Key " << key << " --> " << str << endl;
        }
    }
}

void encode() {
    string str;
    cout << "Enter the string to encode: ";
    cin.ignore(); // To clear the newline character left in the buffer
    getline(cin, str); // Using getline to capture full string including spaces
    long long key;
    cout << "Enter key for encryption: ";
    cin >> key;
    key = key % 26
