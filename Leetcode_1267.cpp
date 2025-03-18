// Leetcode 1267
#include<bits/stdc++.h>
using namespace std;

int countServers(vector<vector<int>>& grid) {
    queue<pair<int, int>> servers;
    int m = grid.size(), n = grid.at(0).size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(grid[i][j]) {
                pair<int, int> coordinate;
                coordinate.first = i;
                coordinate.second = j;
                servers.push(coordinate);
            } 
        }
    }

    int count = 0;
    while(!servers.empty()) {
        pair<int, int> coordinate = servers.front();
        int x = coordinate.first, y = coordinate.second;
        bool communicate = false;
        for(int i = 0; i < m; i++) {
            if(i == x) continue;
            if(communicate) break;
            if(grid[i][y] == 1) communicate = true;
        }

        for(int i = 0; i < n; i++) {
            if(i == y) continue;
            if(communicate) break;
            if(grid[x][i] == 1) communicate = true;
        }

        if(communicate) count++;
        servers.pop();
    }

    return count;
}

int main () {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) cin >> grid[i][j];
    }

    int output = countServers(grid);
    cout << output << endl;
    return 0;
}