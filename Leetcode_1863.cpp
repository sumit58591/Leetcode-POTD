#include <bits/stdc++.h>
using namespace std;

int subsetXORSum_helper(vector<int>& nums, int startIndex, int XORSum) {
    if(startIndex >= nums.size()) return XORSum;
    int smallOutput1 = subsetXORSum_helper(nums, startIndex + 1, XORSum ^ nums[startIndex]);
    int smallOutput2 = subsetXORSum_helper(nums, startIndex + 1, XORSum);
    return smallOutput1 + smallOutput2;
}

int subsetXORSum(vector<int>& nums) {
    int startIndex = 0, n = nums.size();
    return subsetXORSum_helper(nums, 0, 0);
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int subsetXOROutput = subsetXORSum(nums);
    cout << subsetXOROutput << endl;
    return 0;
}