#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& nums, int k) {
    int output = 0, n = nums.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] == nums[j] and (i * j) % k == 0) output++;
        }
    }    

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int k;
    cin >> k;
    int countPairsOutput = countPairs(nums, k);
    cout << countPairsOutput << endl;
}