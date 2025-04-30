#include <bits/stdc++.h>
using namespace std;

bool isEven(int n) {
    return (n % 2) == 0;
}

int findNumbers(vector<int>& nums) {
    int outputCount = 0;
    for(int i = 0; i < nums.size(); i++) {
        int currDigitCount = log10(nums[i]) + 1;
        if(isEven(currDigitCount)) outputCount++;
    }

    return outputCount;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int outputCount = findNumbers(arr);
    cout << outputCount << endl;
    return 0;
}