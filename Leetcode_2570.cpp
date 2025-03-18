// Leetcode 2570
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    vector<vector<int>> output;
    int i = 0, j = 0, k = 0;
    while(i < nums1.size() and j < nums2.size()) {
        if(nums1[i][0] == nums2[j][0]) {
            output.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
            i++; j++;
        } else {
            if(nums1[i][0] < nums2[j][0]) {
                output.push_back({nums1[i][0], nums1[i][1]});
                i++;
            } else {
                output.push_back({nums2[j][0], nums2[j][1]});
                j++;
            }
        }
    }

    while(i < nums1.size()) 
        output.push_back({k + 1, nums1[i++][1]}); k++;
    while(j < nums2.size()) output.push_back({k + 1, nums2[j++][1]}); k++;
    return output;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> arr1(n, vector<int>(2));
    vector<vector<int>> arr2(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) cin >> arr1[i][j];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) cin >> arr2[i][j];
    }
    
    vector<vector<int>> sumOutput =  mergeArrays(arr1, arr2);
    for(int i = 0; i < sumOutput.size(); i++) {
        for(int j = 0; j < 2; j++) cout << sumOutput[i][j] << " ";
        cout << endl;
    }

    return 0;
}