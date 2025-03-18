// Leetcode 3066
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int minOperations(vector<int>& nums, int k) {
    multiset<ll> st;
    int n = nums.size();
    int outputCount = 0;
    for(int i = 0; i < n; i++) st.insert(nums[i]);
    while(st.size() > 1) {
        long long value1 = *st.begin();
        st.erase(st.begin());
        if(value1 >= k) break;
        long long value2 = *st.begin();
        st.erase(st.begin());
        long long currOperationValue = (value1 * 2) + value2;
        st.insert(currOperationValue);
        outputCount++;
    }

    return outputCount;
}   

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    int output = minOperations(arr, k);
    cout << output << endl;
    return 0;
}