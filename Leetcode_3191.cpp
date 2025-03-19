// Leetcode 3191
#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums) {
    int n = nums.size(), i = 0;
    int minOperationsOutput = 0;
    while(i < n - 2) {
        if(nums[i] == 0) {
            int j = i;
            while(j < n and j - i + 1 != 3) {
                nums[j] = !nums[j];
                j++;
            }
            
            if(j < n and j - i + 1 == 3) nums[j] = !nums[j];
            minOperationsOutput++;
        }

        i++;
    }

    for(int i = 0; i < n; i++) if(nums[i] == 0) return -1;
    return minOperationsOutput;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int minOperationsOutput = minOperations(nums);
    cout << minOperationsOutput << endl;
    return 0;
}