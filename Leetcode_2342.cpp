// Leetcode 2342
#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int num) {
    int sum = 0;
    while(num != 0) {
        sum += num % 10;
        num /= 10;
    }

    return sum;
}

int maximumSum(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, vector<int>> mp;
    for(int i = 0; i < n; i++) mp[sumOfDigits(nums[i])].push_back(nums[i]);
    int maximumSumOutput = -1;
    for(auto &array : mp) {
        sort(array.second.begin(), array.second.end());
        if(array.second.size() >= 2) {
            int currentSum = array.second.back() + array.second[array.second.size() - 2];
            maximumSumOutput = max(maximumSumOutput, currentSum);
        }
    }

    return maximumSumOutput;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int maximumSumOutput = maximumSum(nums);
    cout << maximumSumOutput << endl;
    return 0;
}