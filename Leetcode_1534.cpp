#include <bits/stdc++.h>
using namespace std;

int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
    int outputCount = 0, n = arr.size();
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(abs(arr[i] - arr[j]) <= a) {
                for(int k = j + 1; k < n; k++) {
                    if(abs(arr[j] - arr[k]) <= b and abs(arr[i] - arr[k]) <= c) outputCount++;
                }
            }
        }
    }

    return outputCount;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int a, b, c;
    cin >> a >> b >> c;
    int goodTripletsCount = countGoodTriplets(arr, a, b, c);
    cout << goodTripletsCount << endl;
    return 0;
}