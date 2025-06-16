#include <bits/stdc++.h>
using namespace std;

int maximumDifference(vector<int>& arr) {
    int maxOutput = -1;
    for(int i = 0; i < arr.size(); i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] > arr[i]) maxOutput = max(maxOutput, arr[j] - arr[i]);
        }
    }
    return maxOutput;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int differenceOutput = maximumDifference(arr);
    cout << differenceOutput << endl;
    return 0;
}