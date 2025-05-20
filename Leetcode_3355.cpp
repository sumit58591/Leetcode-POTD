#include <bits/stdc++.h>
using namespace std;

bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> diff(n + 1, 0);
    for(int i = 0; i < queries.size(); i++) {
        int l = queries[i][0], r = queries[i][1];
        diff[l]++;
        diff[r + 1]--;
    }
    
    int sum = 0;
    for(int i = 0; i <= n; i++) {
        sum += diff[i];
        diff[i] = sum;
    }

    for(int i = 0; i < n; i++) {
        if(diff[i] < nums[i]) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int noOfQueries;
    cin >> noOfQueries;
    vector<vector<int>> queries(noOfQueries, vector<int>(2));
    for(int i = 0; i < noOfQueries; i++) {
        for(int j = 0; j < 2; j++) cin >> queries[i][j];
    }

    bool output = isZeroArray(nums, queries);
    if(output) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}