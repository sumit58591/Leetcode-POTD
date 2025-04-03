#include <bits/stdc++.h>
using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    vector<int> rightMaxValue(nums.size());
    rightMaxValue[nums.size() - 1] = nums[nums.size() - 1];
    for(int i = nums.size() - 2; i >= 2; i--) {
        rightMaxValue[i] = max(rightMaxValue[i + 1], nums[i]);
    }
    
    long long output = 0;
    long long maxX = nums[0];
    for(int i = 1; i < nums.size() - 1; i++) {
        long long currY = nums[i];
        long long currTriplet = (maxX - currY) * rightMaxValue[i + 1];
        maxX = max(maxX, currY);
        output = max(output, currTriplet);
    }

    return output < 0 ? 0 : output;
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