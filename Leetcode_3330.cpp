#include <bits/stdc++.h>
using namespace std;

int possibleStringCount(string word) {
    char prevChar = word[0];
    int outputCount = 0;
    for(int i = 1; i < word.size(); i++) {
        if(word[i] == prevChar) {
            outputCount++;
            prevChar = word[i];
        }
    }

    return outputCount + 1;
}

int main() {
    string word;
    cin >> word;
    int outputCount = possibleStringCount(word);
    cout << outputCount << endl;
    return 0;
}