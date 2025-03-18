#include <bits/stdc++.h>
using namespace std;

int lastOccurenceOfNegative(vector<int>& nums) {
    int si = 0, ei = nums.size() - 1;
    while(si <= ei) {
        int mid = (si + ei) / 2;
        if(nums[mid] >= 0) ei = mid - 1;
        else si = mid + 1;
    }

    return ei;
}

int firstOccurenceOfPositive(vector<int>& nums) {
    int si = 0, ei = nums.size() - 1;
    while(si <= ei) {
        int mid = (si + ei) / 2;
        if(nums[mid] <= 0) si = mid + 1;
        else ei = mid - 1;
    }

    return si;
}

int maximumCount(vector<int>& nums) {
    int negativeCount = lastOccurenceOfNegative(nums) + 1;
    int positiveCount = nums.size() - firstOccurenceOfPositive(nums);
    return max(negativeCount, positiveCount);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int output = maximumCount(arr);
    cout << output << endl;
    return 0;
}