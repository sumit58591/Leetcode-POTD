// Leetcode 2948
#include<bits/stdc++.h>
using namespace std;

vector<int> lexicographicallySmallestArray_brute(vector<int>& arr, int limit) {
    int n = arr.size();
    int k = 0;
    while(k < n) {
        for(int i = 0; i < n; i++) {
            int currEle = arr[i];
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                if(abs(arr[i] - arr[j]) <= limit and arr[j] < arr[i]) {
                    arr[i] = arr[j];
                    arr[j] = currEle;
                    currEle = arr[i];
                }

                if(abs(arr[i] - arr[j]) <= limit and arr[i] < arr[j]) {
                    arr[j] = arr[i];
                    arr[i] = currEle;
                    currEle = arr[j];
                }
            }
        }
    }
    return arr;  
}

vector<int> lexicographicallySmallestArray(vector<int>& arr, int limit) {
        int n = arr.size();
        vector<pair<int, int>> indexed;
        for(int i = 0; i < arr.size(); i++) indexed.push_back({arr[i], i});
        sort(indexed.begin(), indexed.end());

        vector<vector<int>> groups = {{indexed[0].second}};
        for(int i = 1; i < n; i++) {
            if((indexed[i].first - indexed[i - 1].first) <= limit) {
                groups.back().push_back(indexed[i].second);
            } else {
                groups.push_back({indexed[i].second});
            }
        }

        for(auto group : groups) {
            vector<int> sortedVals;
            for(auto i : group) sortedVals.push_back(arr[i]);
            sort(sortedVals.begin(), sortedVals.end());
            sort(group.begin(), group.end());
            for(int i = 0; i < group.size(); i++) arr[group[i]] = sortedVals[i];
        }
        
        return arr;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int limit;
    cin >> limit;
    vector<int> output = lexicographicallySmallestArray(arr, limit);
    for(int i = 0; i < n; i++) cout << output[i] << " ";
    return 0;
}