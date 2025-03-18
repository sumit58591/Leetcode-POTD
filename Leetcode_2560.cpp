// Leetcode 2560
#include <bits/stdc++.h>
using namespace std;

bool canRob(vector<int>& nums, int mid, int k) {
    int count = 0, n = nums.size();
    for(int i = 0; i < n; i++) {
        if(nums[i] <= mid) {
            count++;
            i++;
        }
    }

    return count >= k;
}

int minCapability(vector<int>& nums, int k) {
    int left = 1, right = *max_element(nums.begin(), nums.end()), ans = right;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(canRob(nums, mid, k)) {
            ans = mid;
            right = mid - 1;
        } else left = mid + 1;
    }

    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    int output = minCapability(arr, k);
    cout << output << endl;
    return 0;
}