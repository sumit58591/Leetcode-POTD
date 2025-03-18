// Leetcode  3306
#include <bits/stdc++.h>
using namespace std;

#define ll long long

bool isVowel(char c) {
    return true ? (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') : false;
}

long long countOfSubstrings_helper(string word, int k) {
    ll outputCount = 0;
    int i = 0, j = 0, n = word.size();
    int consonentsCount = 0;
    unordered_map<char, int> mp;
    while(j < n) {
        if(isVowel(word[j])) mp[word[j]]++;
        else consonentsCount++;
        while(consonentsCount >= k) {
            if(isVowel(word[i])) {
                mp[word[i]]--;
                if(mp[word[i]] == 0) mp.erase(word[i]);
            } else consonentsCount--;

            if(mp.size() == 5) outputCount = (ll) (n - j);
            i++;
        }

        j++;
    }

    return outputCount;
}

long long countOfSubstrings(string word, int k) {
    return countOfSubstrings_helper(word, k) - countOfSubstrings_helper(word, k + 1);
}

int main() {
    string word;
    cin >> word;
    int k;
    cin >> k;
    long long output = countOfSubstrings(word, k);
    cout << output << endl;
}