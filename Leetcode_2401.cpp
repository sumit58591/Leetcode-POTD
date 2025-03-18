// Leetcode 2401
#include <bits/stdc++.h>
using namespace std;

int longestNiceSubarray(vector<int>& nums) {
    int currSum = 0, xorSum = 0;
    int i = 0, j = 0, n = nums.size(), output = 0;
    while(j < n) {
        currSum += nums[j];
        xorSum ^= nums[j];
        while(currSum != xorSum and i <= j) {
            currSum -= nums[i];
            xorSum ^= nums[i];
            i++;
        }

        output = max(output, j - i + 1);
        j++;
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int output = longestNiceSubarray(arr);
    cout << output << endl;
    return 0;
}