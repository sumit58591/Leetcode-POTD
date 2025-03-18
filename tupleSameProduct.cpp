// Leetcode 1762
#include<bits/stdc++.h>
using namespace std;

int tupleSameProduct(vector<int>& nums) {
    int n = nums.size();
    int output = 0;
    unordered_map<int, int> mp;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int product = nums[i] * nums[j];
            output += (8 * mp[product]);
            mp[product]++;
        }
    }

    return output;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int output = tupleSameProduct(arr);
    cout << output << endl;
    return 0;
}