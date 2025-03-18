// Leetcode 2161
#include <bits/stdc++.h>
using namespace std;

vector<int> pivotArray(vector<int>& nums, int pivot) {
    int i = 0, j = nums.size();
    int left = 0, right = j;
    vector<int> output(nums.size());
    while(i < nums.size() and j >= 0) {
        if(nums[i] < pivot) {
            output[left++] = nums[i];
            i++;
        }

        if(nums[j] > pivot) {
            output[right--] = nums[j];
            j--;
        }
    }

    while(left <= right) {
        nums[left++] = pivot;
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int pivot;
    cin >> pivot;
    vector<int> output = pivotArray(arr, pivot);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}