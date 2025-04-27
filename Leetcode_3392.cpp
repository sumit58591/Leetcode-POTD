#include <bits/stdc++.h>
using namespace std;

int countSubarrays(vector<int>& nums) {
    int i = 0, j = 0, n = nums.size();
    int windowSum = 0, countOutput = 0;
    while(j < n) {
        if(j - i + 1 < 3) windowSum += nums[j];
        while(j - i + 1 > 3) {
            windowSum -= nums[i];
            i++;
        }

        if((j - i + 1) == 3) {
            int firstThirdSum = nums[i] + nums[j];
            double halfOfMiddle = ((1.0) * nums[i + 1]) / 2;
            if(halfOfMiddle == firstThirdSum) countOutput++;
        }

        j++;
    }

    return countOutput;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int countOutput = countSubarrays(nums);
    cout << countOutput << endl;
    return 0;
}

// [1 2 1 4 1]