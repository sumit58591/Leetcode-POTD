// Leetcode 2017
#include<bits/stdc++.h>
using namespace std;

long long gridGame(vector<vector<int>>& arr) {
    long long output = LLONG_MAX;
    int n = arr[0].size();
    vector<long long> top(n + 1), bottom(n + 1);
    top[n] = 0, bottom[0] = 0;
    for(int i = 1; i <= n; i++) bottom[i] = bottom[i - 1] + arr[1][i - 1];
    for(int i = n - 1; i >= 0; i--) top[i] = top[i + 1] + arr[0][i];

    vector<long long> maximumPointsBySecondRobot;
    for(int i = 1; i <= n; i++) {
        long long maximumPoints = max(top[i], bottom[i - 1]);
        maximumPointsBySecondRobot.push_back(maximumPoints);
    }

    int size = maximumPointsBySecondRobot.size();
    for(int i = 0; i < size; i++) output = min(output, maximumPointsBySecondRobot[i]);
    return output;
}

long long gridGame_brute(vector<vector<int>>& arr) {
    long long finalOutput = LLONG_MAX;
    vector<long long> maxPoints;
    int n = arr.at(0).size();
    for(int i = 0; i < n; i++) {
        long long currSumRightTop = 0, currSumLeftBottom = 0;
        long long currMax = LLONG_MIN;
        for(int j = i + 1; j < n; j++) {
            currSumRightTop += arr[0][j];
        }

        for(int j = 0; j < i; j++) {
            currSumLeftBottom += arr[1][j];
        }

        maxPoints.push_back(max(currSumLeftBottom, currSumRightTop));
    }

    for(int i = 0; i < maxPoints.size(); i++) finalOutput = min(finalOutput, maxPoints[i]);
    return finalOutput;
}

int main () {
    int n;
    cin >> n;
    vector<vector<int>> arr(2, vector<int>(n));
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++) cin >> arr[i][j];
    }
    long long output = gridGame_brute(arr);
    cout << output << endl;
    return 0;
}