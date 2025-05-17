#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0, n = nums.size();
    for(int i = 0; i < n; i++) {
        if(nums[i] == 0) count0++;
        else if(nums[i] == 1) count1++;
        else count2++;
    } 

    int i = 0;
    while(count0--) {
        nums[i++] = 0;
    }

    while(count1--) {
        nums[i++] = 1;
    }

    while(count2--) {
        nums[i++] = 2;
    }

    return;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}