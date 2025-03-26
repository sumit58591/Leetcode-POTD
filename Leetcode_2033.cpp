#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<vector<int>>& grid, int x) {
    vector<int> arr;
    int rem = grid[0][0] % x;
    int minOperationsOutput = 0;
    for(int i = 0; i < grid.size(); i++) {
        for(int j = 0; j < grid.at(i).size(); j++) {
            if(grid[i][j] % x != rem) return -1; 
            arr.push_back(grid[i][j]);
        }
    }        
    
    sort(arr.begin(), arr.end());
    int midIndex = arr.size() / 2, midElement = arr[midIndex];
    for(int i = 0; i < arr.size(); i++) {
        minOperationsOutput += (abs(midElement - arr[i])) / x;
    }

    return minOperationsOutput;
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) cin >> grid[i][j];
    }

    int x;
    cin >> x;
    int output = minOperations(grid, x);
    cout << output << endl;
    return 0;
}