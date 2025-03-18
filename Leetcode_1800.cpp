// Leetcode 1800
#include<bits/stdc++.h>
using namespace std;

int maxAscendingSum(vector<int>& arr) {
    int n = arr.size();
    int i = 0, j = 1;
    if(n == 1) return arr[0];
    int currSum = arr[0], maxAscendingSumOutput = arr[0];
    while(j < n) {
        if(arr[j] > arr[i]) currSum += arr[j];
        else currSum = arr[j];
        maxAscendingSumOutput = max(maxAscendingSumOutput, currSum);
        i++; j++;
    }

    return maxAscendingSumOutput;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int output = maxAscendingSum(arr);
    cout << output << endl; 
}