#include <bits/stdc++.h>
using namespace std;

vector<int> findWordsContaining(vector<string>& words, char x) {
    vector<int> output;
    for(int i = 0; i < words.size(); i++) {
        size_t pos = words[i].find(x);
        if(pos == string::npos) continue;
        else output.push_back(i);
    }       

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    char x;
    cin >> x;
    vector<int> outputIndexes = findWordsContaining(words, x);
    for(int i = 0; i < outputIndexes.size(); i++) cout << outputIndexes[i] << " ";
    return 0;
}