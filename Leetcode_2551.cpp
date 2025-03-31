#include <bits/stdc++.h>
using namespace std;

long long putMarbles(vector<int>& weights, int k) {
    vector<int> consecutiveSums;
    int n = weights.size();
    for(int i = 0; i < n - 1; i++) {
        consecutiveSums.push_back(weights[i] + weights[i + 1]);
    }

    sort(consecutiveSums.begin(), consecutiveSums.end());
    long long maxSum = 0, minSum = 0;
    for(int i = 0; i < k - 1; i++) {
        minSum += consecutiveSums[i];
        maxSum += consecutiveSums[n - 2 - i];
    }

    return maxSum - minSum;
}

int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    for(int i = 0; i < n; i++) cin >> weights[i];
    int k;
    cin >> k;
    long long putMarblesOutput = putMarbles(weights, k);
    cout << putMarblesOutput << endl;
    return 0;
}