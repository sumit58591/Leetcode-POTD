// Leetcode 2594
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

bool isTimeSufficient(vector<int>& ranks, int cars, int minTime) {
    ll totalCarCount = 0;
    for(auto rank: ranks) {
        ll carCountSquare = minTime / rank;
        ll carCount = floor(sqrt(carCountSquare));

        totalCarCount += carCount;
    }

    return (totalCarCount >= cars);
}

long long repairCars(vector<int>& ranks, int cars) {
    ll l = 0, r = ranks.size() - 1;        
    while(l < r) {
        ll mid = (l + r) / 2;
        if(isTimeSufficient(ranks, cars, mid)) r = mid;
        else l = mid + 1;
    }

    return l;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int cars;
    cin >> cars;
    long long output = repairCars(arr, cars);
    cout << output << endl;
    return 0;
}