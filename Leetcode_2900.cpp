#include <bits/stdc++.h>
using namespace std;

void getSubsequence(vector<int>& groups, queue<int>& q, int lastVal) {
    for(int i = 0; i < groups.size(); i++) {
        if(groups[i] == lastVal) continue;
        else {
            lastVal = groups[i];
            q.push(i);
        }
    }
}

vector<string> getLongestSubsequenceOutput(vector<string>& words, queue<int>& q) {
    vector<string> output;
    while(!q.empty()) {
        output.push_back(words[q.front()]);
        q.pop();
    }

    return output;
}

vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
    queue<int> q1, q2;
    getSubsequence(groups, q1, 0);
    getSubsequence(groups, q2, 1);
    vector<string> output;
    return q1.size() > q2.size() ? getLongestSubsequenceOutput(words, q1) : getLongestSubsequenceOutput(words, q2);
}

int main() {
    int n;
    cin >> n;
    vector<string> words(n);
    vector<int> groups(n);
    for(int i = 0; i < n; i++) cin >> words[i];
    for(int i = 0; i < n; i++) cin >> groups[i];
    vector<string> output = getLongestSubsequence(words, groups);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}