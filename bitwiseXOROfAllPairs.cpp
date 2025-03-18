// Leetcode 2425
#include<iostream>
#include<vector>
using namespace std;

int xorAllNums(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size(), n = arr2.size(), finalXOR = 0;
    if(m % 2 != 0 and n % 2 != 0) {
        int xor1 = 0, xor2 = 0;
        for(int i = 0; i < m; i++) xor1 ^= arr1[i];
        for(int i = 0; i < n; i++) xor2 ^= arr2[i];
        finalXOR = xor1 ^ xor2;
        return finalXOR;
    } else if(m % 2 == 0 and n % 2 == 0) {
        return 0;
    } else if(m % 2 == 0) {
        for(int i = 0; i < m; i++) finalXOR ^= arr1[i];
        return finalXOR;
    } else {
        for(int i = 0; i < n; i++) finalXOR ^= arr2[i];
        return finalXOR;
    }
}

int xorAllNums_brute(vector<int>& arr1, vector<int>& arr2) {
    vector<int> xorVal;
    int m = arr1.size(), n = arr2.size();
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int currXOR = arr1[i] ^ arr2[j];
            xorVal.push_back(currXOR);
        }
    }

    int finalXOR = 0;
    for(int i = 0; i < xorVal.size(); i++) finalXOR ^= xorVal[i];
    return finalXOR;
}

int main () {
    int m, n;
    cin >> m >> n;
    vector<int> arr1(m), arr2(n);
    for(int i = 0; i < m; i++) cin >> arr1[i];
    for(int i = 0; i < n; i++) cin >> arr2[i];
    int output = xorAllNums(arr1, arr2);
    cout << output << endl;
    return 0;
}