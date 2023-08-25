#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int PRIME = 11;

void rabinKarp(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int patternHash = 0; 
    int textHash = 0; 
    int i, j;

    for (i = 0; i < m; i++) {
        patternHash += pattern[i] % PRIME;
        textHash += text[i] % PRIME;
    }
    
    for (i = 0; i <= n-m; i++) {
        if (patternHash == textHash) {
            for (j = 0; j < m; j++) {
                if (text[i+j] != pattern[j])
                    break;
            }
            if (j == m) {
                cout << "Pattern found at index: " << i << endl;
            }
        }

    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    rabinKarp(text, pattern);

    return 0;
}
