// Leetcode 1749
#include <bits/stdc++.h>
using namespace std;

int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixSum;
    prefixSum.push_back(0);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += nums[i];
        prefixSum.push_back(sum);
    }

    int maxOutput = 0;
    int maxAbsoluteSumOutput = 0, minSum = 0, maxSum = 0;
    for(int i = 0; i < prefixSum.size(); i++) {
        maxAbsoluteSumOutput = max(maxAbsoluteSumOutput, max(abs(prefixSum[i] - minSum), abs(prefixSum[i] - maxSum)));
        maxSum = max(maxSum, prefixSum[i]);
        minSum = min(minSum, prefixSum[i]);
    }

    return maxAbsoluteSumOutput;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int maxOutput = maxAbsoluteSum(nums);
    cout << maxOutput << endl;
    return 0;
}