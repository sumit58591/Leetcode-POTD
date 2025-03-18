// Leetcode 2657
#include<bits/stdc++.h>
using namespace std;

vector<int> findThePrefixCommonArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> mp;
    int currCommon = 0, n = arr1.size();
    vector<int> output;
    for(int i = 0; i < n; i++) {    
        if(arr1[i] == arr2[i]) {
            currCommon += 1;
            output.push_back(currCommon);
        } else if(mp[arr1[i]] > 0 and mp[arr2[i]] > 0) {
            currCommon += 2;
            output.push_back(currCommon);
        } else if(mp[arr1[i]] > 0 or mp[arr2[i]] > 0) {
            currCommon += 1;
            output.push_back(currCommon);
        } else {
            output.push_back(currCommon);
        }

        mp[arr1[i]]++;
        mp[arr2[i]]++;
    }

    return output;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr1(n), arr2(n);
    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int i = 0; i < n; i++) cin >> arr2[i];
    vector<int> output = findThePrefixCommonArray(arr1, arr2);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}