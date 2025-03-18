// Leetcode 3208
#include <bits/stdc++.h>
using namespace std;

int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int outputCount = 0, i = 0, j = 1, n = colors.size(), windowSize = 1;
    while(j <= n + k - 2) {
        if(colors[j % n] != colors[(j - 1 + n) % n]) {
            windowSize++;
        } else {
            windowSize = 1;
        }

        if(windowSize >= k) outputCount++;
        j++;
    }

    return outputCount++;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    int outputCount = numberOfAlternatingGroups(arr, k);
    cout << outputCount << endl;
    return 0;
}