// Leetcode 3151
#include<bits/stdc++.h>
using namespace std;

bool isOdd(int num) {
    return (num % 2 != 0);
}

bool isEven(int num) {
    return (num % 2 == 0);
}

bool isArraySpecial(vector<int>& nums) {
    int n = nums.size(), i = 0, j = 1;
    while(i < n and j < n) {
        if(isOdd(nums[i]) and isOdd(nums[j])) {
            return false;
        } else if(isEven(nums[i]) and isEven(nums[j])) {
            return false;
        } else {
            i++;
            j++;
        }
    }

    return true;
}

int main () {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    bool output = isArraySpecial(nums);
    if(output) cout << "true";
    else cout << "false";
    return 0;
}