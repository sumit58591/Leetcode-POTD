// Leetcode 1765
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {        
    int m = isWater.size(), n = isWater.at(0).size();
    vector<vector<int>> height(m, vector<int>(n));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    queue<pair<int, int>> waterCoordinates;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            if(isWater[i][j] == 1) {
                pair<int, int> coordinate;
                coordinate.first = i;
                coordinate.second = j;
                waterCoordinates.push(coordinate);
                height[i][j] = 0;
                visited[i][j] = true;
            }
        }
    }
    
    while(!waterCoordinates.empty()) {
        pair<int, int> coordinate = waterCoordinates.front();
        int x = coordinate.first, y = coordinate.second;
        int currHeight = height[x][y] + 1;
        if(x - 1 >= 0 and !visited[x - 1][y]) {
            height[x - 1][y] = currHeight;
            visited[x - 1][y] = true;
            pair<int, int> currCoordinate;
            currCoordinate.first = x - 1;
            currCoordinate.second = y;
            waterCoordinates.push(currCoordinate); 
        }

        if(y + 1 < n and !visited[x][y + 1]) {
            height[x][y + 1] = currHeight;
            visited[x][y + 1] = true;
            pair<int, int> currCoordinate;
            currCoordinate.first = x;
            currCoordinate.second = y + 1;
            waterCoordinates.push(currCoordinate);
        }

        if(x + 1 < m and !visited[x + 1][y]) {
            height[x + 1][y] = currHeight;
            visited[x + 1][y] = true;
            pair<int, int> currCoordinate;
            currCoordinate.first = x + 1;
            currCoordinate.second = y;
            waterCoordinates.push(currCoordinate);
        }

        if(y - 1 >= 0 and !visited[x][y - 1]) {
            height[x][y - 1] = currHeight;
            visited[x][y - 1] = true;
            pair<int, int> currCoordinate;
            currCoordinate.first = x;
            currCoordinate.second = y - 1;
            waterCoordinates.push(currCoordinate);
        }

        waterCoordinates.pop();
    }

    return height;
}

int main () {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> isWater(m, vector<int>(n));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) cin >> isWater[i][j];
    }

    vector<vector<int>> height = highestPeak(isWater);
    for(int i = 0; i < height.size(); i++) {
        for(int j = 0; j < height.at(i).size(); j++) {
            cout << height[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}