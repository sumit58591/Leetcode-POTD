// Leetcode 2364
#include <bits/stdc++.h>
using namespace std;

long long countBadPairs(vector<int>& nums) {
    int n = nums.size();
    long long totalNumberOfPairs = ((long long) n * (n - 1)) / 2, goodPairs = 0;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) mp[nums[i] - i]++;
    for(auto &it : mp) goodPairs += ((long long) it.second * (it.second - 1)) / 2;
    return totalNumberOfPairs - goodPairs;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    long long countBadPairsOutput = countBadPairs(arr);
    cout << countBadPairsOutput << endl;
    return 0;
}