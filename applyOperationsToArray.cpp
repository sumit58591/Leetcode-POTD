// Leetcode 2460
#include <bits/stdc++.h>
using namespace std;

vector<int> applyOperations(vector<int>& nums) {
    int n = nums.size();
    for(int i = 0; i < n - 1; i++) {
        if(nums[i] == 0) continue;
        if(nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }

    int i = 0, j = 0;
    while(j < n) {
        if(nums[j] != 0) {
            nums[i] = nums[j];
            i++;
            j++;
        } else {
            j++;
        }
    }

    while(i < n) nums[i++] = 0;
    return nums;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> output = applyOperations(arr);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}