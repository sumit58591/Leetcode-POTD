#include <bits/stdc++.h>
using namespace std;

vector<int> buildArray(vector<int>& nums) {
    vector<int> ans(nums.size());
    for(int i = 0; i < nums.size(); i++) ans[i] = nums[nums[i]];
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    vector<int> outputArray = buildArray(nums);
    for(int i = 0; i < outputArray.size(); i++) cout << outputArray[i] << " ";
    return 0;
}