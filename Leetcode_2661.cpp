// Leetcode 2661
#include<bits/stdc++.h>
using namespace std;

int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    unordered_map<int, int> mp;
    int arraySize = arr.size();
    for(int i = 0; i < arraySize; i++) mp[arr[i]] = i;
    int m = mat.size(), n = arraySize / m;
    int finalOutput = INT_MAX;

    for(int i = 0; i < m; i++) {
        int currMax = 0;
        for(int j = 0; j < n; j++) {
            int currentIndex = mp[mat[i][j]];
            currMax = max(currentIndex, currMax);
        }

        finalOutput = min(currMax, finalOutput);
    }

    for(int i = 0; i < n; i++) {
        int currMax = 0;
        for(int j = 0; j < m; j++) {
            int currentIndex = mp[mat[j][i]];
            currMax = max(currentIndex, currMax);
        }

        finalOutput = min(currMax, finalOutput);
    }

    return finalOutput;
}

int main () {
    int size;
    cin >> size;
    vector<int> arr(size);
    for(int i = 0; i < size; i++) cin >> arr[i];
    int m, n;
    cin >> m >> n;
    vector<vector<int>> mat(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int output = firstCompleteIndex(arr, mat);
    cout << output << endl;
    return 0;
}