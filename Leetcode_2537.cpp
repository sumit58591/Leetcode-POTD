#include <bits/stdc++.h>
using namespace std;

long long countGood(vector<int>& arr, int k) {
    long long outputCount = 0;
    int i = 0, j = 0, n = arr.size(), pairCount = 0;
    unordered_map<int, int> mp;
    while(j < n) {
        mp[arr[j]]++;
        if(mp[arr[j]] > 1) pairCount += mp[arr[j]] - 1;
        while(i < n and pairCount >= k) {
            mp[arr[i]]--;
            pairCount -= mp[arr[i]];
            outputCount += n - j;
            i++;
        }

        j++;
    }

    return outputCount;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int k;
    cin >> k;
    long long output = countGood(arr, k);
    cout << output << endl;
    return 0;
}