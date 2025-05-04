#include <bits/stdc++.h>
using namespace std;

int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int outputCount = 0;
    map<pair<int, int>, int> mp;
    for(int i = 0; i < dominoes.size(); i++) {
        sort(dominoes[i].begin(), dominoes[i].end());
    }   

    for(int i = 0; i < dominoes.size(); i++) {
        pair<int, int> currPair({dominoes[i][0], dominoes[i][1]});
        if(mp.find(currPair) != mp.end()) outputCount += mp[currPair];
        mp[currPair]++;
    }

    return outputCount;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> dominoes(n, vector<int>(2, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) cin >> dominoes[i][j];
    }

    int pairsOutput = numEquivDominoPairs(dominoes);
    cout << pairsOutput << endl;
    return 0;
}