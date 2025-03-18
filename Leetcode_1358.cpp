// Leetcode 1358
#include <bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string s) {
    unordered_map<char, int> mp;
    int i = 0, j = 0, n = s.length(), outputCount = 0;
    while(j < n) {
        mp[s[j]]++;
        while(mp.size() == 3) {
            outputCount += n - j;
            mp[s[i]]--;
            if(mp[s[i]] == 0) mp.erase(s[i]);
            i++;
        }

        j++;
    }

    return outputCount;
}

int main() {
    string str;
    cin >> str;
    int output = numberOfSubstrings(str);
    cout << output << endl;
    return 0;
}