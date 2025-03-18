// Leetcode 1980
#include <bits/stdc++.h>
using namespace std;

string getUniqueBinaryString(int n, string current, unordered_set<string> &numsSet) {
    if(current.length() == n) {
        if(numsSet.find(current) == numsSet.end()) {
            return current;
        }

        return "";
    }

    string addZero = getUniqueBinaryString(n, current + '0', numsSet);
    if(addZero.length() > 0) return addZero;
    return getUniqueBinaryString(n, current + '1', numsSet);
}

string findDifferentBinaryString(vector<string>& nums) {
    unordered_set<string> st;
    for(auto &str : nums) st.insert(str);
    int n = nums.size();
    string uniqueBinaryString = getUniqueBinaryString(n, "", st);
    return uniqueBinaryString;        
}

int main() {
    int n;
    cin >> n;
    vector<string> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    string output = findDifferentBinaryString(nums);
    cout << output << endl;
    return 0;
}