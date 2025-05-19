#include <bits/stdc++.h>
using namespace std;

string triangleType(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    if(nums[0] == nums[2]) return "equilateral";
    else if(nums[0] == nums[1] or nums[1] == nums[2]) {
        if(nums[0] + nums[1] > nums[2]) return "isosceles";
        else return "none";
    } else {
        if(nums[0] + nums[1] > nums[2]) return "scalene";
        else return "none"; 
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    string str = triangleType(arr);
    cout << str << endl;
    return 0;
}