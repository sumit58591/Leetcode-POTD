#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int>& nums, int k) {
    int maxElement = INT_MIN;
    for(int i = 0; i < nums.size(); i++) maxElement = max(maxElement, nums[i]);
    int i = 0, j = 0, n = nums.size();
    long long outputCount = 0;
    int currCount = 0;
    while(j < n) {
        if(nums[j] == maxElement) currCount++;
        while(currCount >= k) {
            if(nums[i] == maxElement) currCount--;
            i++;
            outputCount += (long long)(n - j);
        }
        
        j++;
    }

    return outputCount;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int k;
    cin >> k;
    long long outputCount = countSubarrays(nums, k);
    cout << outputCount << endl;
    return 0;
}