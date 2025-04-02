#include <bits/stdc++.h>
using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    int n = nums.size();
    long long output = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                long long currVal = ((long long)nums[i] - nums[j]) * (long long)nums[k];
                output = max(output, currVal);
            }
        }
    }       

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    long long maximumTripletValueOutput = maximumTripletValue(arr);
    cout << maximumTripletValueOutput << endl;
    return 0;
}