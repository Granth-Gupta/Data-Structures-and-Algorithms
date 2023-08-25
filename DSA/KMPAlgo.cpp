#include <iostream>
#include <string>
#include <vector>

using namespace std;

void computeLPS(string pattern, vector<int>& lps) {
    int n = pattern.size();
    lps.resize(n);

    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void search(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> lps;
    computeLPS(pattern, lps);

    int i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
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
    search(text, pattern);
    return 0;
}
