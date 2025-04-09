#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums, int k) {
    set<int> st;
    bool allEqual = true;
    for(int i = 0; i < nums.size(); i++) {
        if(nums[i] < k) return -1;
        if(nums[i] > k) {
            st.insert(nums[i]);
            allEqual = false;
        }
    }
    
    if(allEqual and nums[0] == k) return 0;
    return st.size() > 0 ? st.size() : -1;
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
}