#include <bits/stdc++.h>
using namespace std;

int minimumIndex(vector<int>& nums) {
    unordered_map<int, int> mp;
    int n = nums.size(), maxFreqElement, maxFreq = 0;
    for(int i = 0; i < n; i++) {
        mp[nums[i]]++;
        if(mp[nums[i]] > maxFreq) {
            maxFreq = mp[nums[i]];
            maxFreqElement = nums[i];
        }
    }

    int maxElementCurrCount = 0;
    for(int i = 0; i < n - 1; i++) {
        if(nums[i] == maxFreqElement) {
            maxElementCurrCount++;
            mp[nums[i]]--;
            int firstSplitLength = i + 1;
            int secondSplitLength = n - 1 - i;
            if(maxElementCurrCount > (firstSplitLength / 2) and mp[nums[i]] > (secondSplitLength / 2)) {
                return i;
            }
        }
    }

    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int minimumIndexOutput = minimumIndex(nums);
    cout << minimumIndexOutput << endl;
    return 0;
}