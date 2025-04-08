#include <bits/stdc++.h>
using namespace std;

int minimumOperations(vector<int>& nums) {
    unordered_map<int, int> mp;
    for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
    int i = 0, j = nums.size() - 1;
    int output = 0;
    while(i <= j) {
        if(mp[nums[j]] > 1) {
            int currCount = 0;
            output++;
            while(i <= j and currCount < 3) {
                mp[nums[i]]--;
                i++;
                currCount++;
            }
        } else j--;
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int output = minimumOperations(arr);
    cout << output << endl;
    return 0;
}