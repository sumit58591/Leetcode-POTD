// Leetcode 1790
#include<bits/stdc++.h>
using namespace std;

bool areAlmostEqual(string s1, string s2) {
    int n = s1.length();
    int count = 0;
    for(int i = 0; i < n; i++) if(s1[i] != s2[i]) count++;
    if(count > 2) return false;
    if(count == 0) return true;
    vector<int> freq(256, 0);
    for(int i = 0; i < n; i++) freq[s1[i]]++;
    for(int i = 0; i < n; i++) freq[s2[i]]--;
    for(int i = 0; i < 256; i++) if(freq[i]) return false;
    return true;
}

int main () {
    string s1, s2;
    cin >> s1 >> s2;
    bool output = areAlmostEqual(s1, s2);
    if(output) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}