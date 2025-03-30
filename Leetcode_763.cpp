#include <bits/stdc++.h>
using namespace std;

vector<int> partitionLabels(string s) {
    vector<int> outputArr;
    unordered_map<char, int> farthestDistance;
    for(int i = 0; i < s.length(); i++) farthestDistance[s[i]] = i;
    int last = 0;
    int currFarthest = -1;
    for(int i = 0; i < s.length(); i++) {
        currFarthest = max(farthestDistance[s[i]], currFarthest);
        if(i == currFarthest) {
            outputArr.push_back(i - last + 1);
            last = i + 1;
        }
    }

    return outputArr;
}

int main() {
    string s;
    cin >> s;
    vector<int> output = partitionLabels(s);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}