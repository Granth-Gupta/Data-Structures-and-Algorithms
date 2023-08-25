#include <iostream>
#include <string>

using namespace std;

void naivePatternMatch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    int i, j;

    for (i = 0; i <= n - m; i++) {
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            cout << "Pattern found at index: " << i << endl;
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

    naivePatternMatch(text, pattern);

    return 0;
}
