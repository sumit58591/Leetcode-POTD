// Leetcode 2658
#include<bits/stdc++.h>
using namespace std;

const vector<vector<int>> directions = {{0 , 1}, {1, 0}, {0, -1}, {-1, 0}};

int dfs_count(int row, int col, vector<vector<bool>>& visited, vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    if(row < 0 or row >= m or col < 0 or col >= n or visited[row][col] or grid[row][col] == 0) {
        return 0;
    }

    visited[row][col] = true;
    int currFishCount = grid[row][col];
    for(const auto& dir: directions) {
        currFishCount += dfs_count(row + dir[0], col + dir[1], visited, grid);
    }
    
    return currFishCount;
}

int findMaxFish(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<vector<bool>> visited(rows, vector<bool> (cols, false));
    int maxFishCount = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(grid[i][j] > 0 and !visited[i][j]) {
                maxFishCount = max(maxFishCount, dfs_count(i, j, visited, grid));
            }
        }
    }

    return maxFishCount;
}

int main () {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int> (n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) cin >> grid[i][j];
    }

    int fishCount = findMaxFish(grid);
    cout << fishCount;
    return 0;
}