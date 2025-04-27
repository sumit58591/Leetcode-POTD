#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int>& nums, int minK, int maxK) {
    multiset<int> ms;
    int i = 0, j = 0, n = nums.size();
    int minMinKIndex = n, minMaxKIndex = n, minIndex = n;
    long long outputCount = 0;
    while(j < n) {
        if(nums[j] >= minK and nums[j] <= maxK) {
            if(nums[j] == minK) minMinKIndex = j;
            if(nums[j] == maxK) minMaxKIndex = j;
            minIndex = min(minMinKIndex, minMaxKIndex);
            ms.insert(nums[j]);
        } else {
            i = j + 1;
            minIndex = n;
            minMinKIndex = n;
            minMaxKIndex = n;
            ms.clear();
        }

        if(!ms.empty() and (*ms.begin() == minK) and (*ms.rbegin() == maxK)) {
            outputCount += minIndex - i + 1;
        }

        j++;
    }

    return outputCount;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int minK, maxK;
    cin >> minK >> maxK;
    long long outputCount = countSubarrays(arr, minK, maxK);
    cout << outputCount << endl;
    return 0;
}

// [35054 398719 945315 945315 820417 945315 35054 945315 171832 945315 35054 109750 790964 441974 552913]