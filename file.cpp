#include <bits/stdc++.h>
using namespace std;

vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    vector<pair<int, int>> indexed;
    for(int i = 0; i < nums.size(); i++) indexed.push_back({nums[i], i});
    sort(indexed.begin(), indexed.end());

    vector<vector<int>> groups = {{indexed[0].second}};
    for(int i = 0; i < nums.size(); i++) {
        if((indexed[i].first - indexed[i - 1].first) <= limit) groups.back().push_back(indexed[i].second);
        else groups.push_back({indexed[i].second});
    }

    for(auto group : groups) {
        vector<int> sortedVals;
        for(int i = 0; i < group.size(); i++) sortedVals.push_back(nums[group[i]]);
        sort(group.begin(), group.end());
        for(int i = 0; i < group.size(); i++) nums[group[i]] = sortedVals[i];
    }

    return nums;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int limit;
    cin >> limit;
    vector<int> output = lexicographicallySmallestArray(arr, limit);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}