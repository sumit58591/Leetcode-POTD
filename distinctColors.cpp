#include <bits/stdc++.h>
using namespace std;

vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    unordered_map<int, int> colorMap;
    unordered_map<int, int> revMap;
    int n = queries.size();
    vector<int> output;
    for(int i = 0; i < n; i++) {
        int x = queries[i][0], y = queries[i][1];
        int exY = colorMap[x];
        if(revMap.find(exY) != revMap.end()) {
            revMap[exY]--;
            if(revMap[exY] == 0) revMap.erase(exY);
        }

        colorMap[x] = y;
        revMap[y]++;
        output.push_back(revMap.size());
    }

    return output;
}

int main() {
    int limit;
    cin >> limit;
    int numberOfQueries;
    cin >> numberOfQueries;
    vector<vector<int>> queries(numberOfQueries, vector<int>(2, 0));
    for(int i = 0; i < numberOfQueries; i++) {
        for(int j = 0; j < 2; j++) cin >> queries[i][j];
    }

    cout << endl;
    cout << endl;
    cout << endl;
    vector<int> output = queryResults(limit, queries);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}