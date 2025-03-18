// Leetcode 1752

#include<bits/stdc++.h>
using namespace std;
bool check(vector<int>& nums) {    
    vector<int> arr = nums;
    int n = nums.size();
    int i = 0, j = 1, count = 0;
    while(i < n) {
        if(count > 1) return false;
        if(nums[i] > nums[j]) count++;
        i++;
        j = (j + 1) % n;
    }

    if(count > 1) return false;
    return true;
}

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    bool output = check(arr);
    if(output) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}

