// Leetcode 3105
#include<bits/stdc++.h>
using namespace std;

int longestMonotonicSubarray(vector<int>& arr) {
    int n = arr.size(), i = 0, j = 1;
    if(n <= 1) return n;
    int currSubarrayLength_strictlyIncreasing = 1, maxSubarrayLength = 0;
    while(j < n) {
        if(arr[j] > arr[i]) {
            currSubarrayLength_strictlyIncreasing++;
        } else {
            currSubarrayLength_strictlyIncreasing = 1;
        }

        maxSubarrayLength = max(maxSubarrayLength, currSubarrayLength_strictlyIncreasing);
        i++; j++;
    }

    int currSubarrayLength_strictlyDecreasing = 1;
    i = 0, j = 1;
    while(j < n) {
        if(arr[j] < arr[i]) {
            currSubarrayLength_strictlyDecreasing++;
        } else {
            currSubarrayLength_strictlyDecreasing = 1;
        }

        maxSubarrayLength = max(maxSubarrayLength, currSubarrayLength_strictlyDecreasing);
        i++; j++;
    }

    return maxSubarrayLength;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int output = longestMonotonicSubarray(arr);
    cout << output << endl;
    return 0;
}