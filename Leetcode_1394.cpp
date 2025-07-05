#include <bits/stdc++.h>
using namespace std;

int findLucky(vector<int>& arr) {
    unordered_map<int, int> mp;
    sort(arr.begin(), arr.end());
    reverse(arr.begin(), arr.end());
    for(int i = 0; i < arr.size(); i++) mp[arr[i]]++;
    for(int i = 0; i < arr.size(); i++) if(mp[arr[i]] == arr[i]) return arr[i];
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    int findLuckyOutput = findLucky(arr);
    cout << findLuckyOutput << endl;
    return 0;    
}