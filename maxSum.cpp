// Leetcode 2342
#include <bits/stdc++.h>
using namespace std;

int sumOfDigits_helper(int num) {
    if(num < 10) return num;
    return (num % 10) + sumOfDigits_helper(num / 10);
}

int sumOfDigits(int num) {
    while(num >= 10) {
        num = sumOfDigits_helper(num);
    }

    return num;
}

int maximumSum(vector<int>& nums) {
    
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int output = maximumSum(arr);
    cout << output << endl;
}