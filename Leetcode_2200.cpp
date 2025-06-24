#include <bits/stdc++.h>
using namespace std;

vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
    vector<int> visited(nums.size(), 0);
    vector<int> output;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        if(nums[i] == key) {
            int startIndex = i - k, endIndex = i + k;
            if(startIndex < 0) startIndex = 0;
            if(endIndex >= n) endIndex = n - 1;
            while(startIndex <= endIndex) {
                if(!visited[startIndex]) output.push_back(startIndex);
                visited[startIndex] = 1;
                startIndex++;
            } 
        }
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int key;
    cin >> key;
    int k;
    cin >> k;
    vector<int> output = findKDistantIndices(arr, key, k);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}