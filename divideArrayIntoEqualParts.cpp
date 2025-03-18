// Leetcode 2206
#include <bits/stdc++.h>
using namespace std;

bool divideArray(vector<int>& nums) {
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
    for(int i = 0; i < nums.size(); i++) if(mp[nums[i]] % 2 != 0) return false;
    return true;
}

int main() {
    // cout << (4 ^ 6 ^ 11 ^ 12 ^ 17 ^ 20) << endl;
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    bool output = divideArray(arr);
    if(output) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}