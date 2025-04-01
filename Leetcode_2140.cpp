#include <bits/stdc++.h>
using namespace std;

long long mostPoints_helper(vector<vector<int>>& questions, vector<long long>& memoization, int index, int n) {
    if(index >= n) return 0;
    if(memoization[index] != -1) return memoization[index];
    vector<int> question = questions[index];
    long long currMarks = question[0];
    long long smallOutput1 = currMarks + mostPoints_helper(questions, memoization, index + 1 + question[1], n);
    long long smallOutput2 = mostPoints_helper(questions, memoization, index + 1, n);
    return memoization[index] = max(smallOutput1, smallOutput2);
}

long long mostPoints(vector<vector<int>>& questions) {
    int index = 0, n = questions.size();
    vector<long long> memoization(n, -1);
    return mostPoints_helper(questions, memoization, index, n);
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> questions(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) cin >> questions[i][j];
    }

    long long mostPointsOutput = mostPoints(questions);
    cout << mostPointsOutput << endl;
    return 0;
}