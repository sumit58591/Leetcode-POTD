#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> divideArray(vector<int>& nums, int k) {
    vector<vector<int>> output;
    if(nums.size() < 3) return output;
    sort(nums.begin(), nums.end());
    int leftIndex = 0, rightIndex = 2;
    while(rightIndex < nums.size()) {
        if(nums[rightIndex] - nums[leftIndex] > k) {
            return output;
        } else {
            leftIndex += 3;
            rightIndex += 3;
        }
    }

    int i = 0;
    while(i < nums.size()) {
        vector<int> triplet;
        triplet.push_back(nums[i]);
        triplet.push_back(nums[i + 1]);
        triplet.push_back(nums[i + 2]);
        i += 3;
        output.push_back(triplet);
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    vector<vector<int>> output = divideArray(arr, k);
    for(int i = 0; i < output.size(); i++) {
        for(int j = 0; j < output.at(i).size(); j++) {
            cout << output[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}