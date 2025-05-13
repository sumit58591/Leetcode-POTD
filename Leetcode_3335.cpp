#include <bits/stdc++.h>
using namespace std;

 int lengthAfterTransformations(string s, int t) {
    int arr[256] = {0};
    int mod = 1e9 + 7;
    for(int i = 0; i < s.length(); i++) arr[s[i]]++;
    while(t--) {
        int nextState[256] = {0};
        for(int i = 97; i < 123; i++) {
            if(i == 122 and arr[i] > 0) {
                nextState[97] += arr[i];
                nextState[97] %= mod;
                nextState[98] += arr[i];
                nextState[98] %= mod;
            } 

            if(arr[i] > 0) {
                nextState[i + 1] = arr[i];
            }
        }

        for(int i = 97; i < 123; i++) arr[i] = nextState[i];
    }

    int output = 0;
    for(int i = 97; i < 123; i++) {
        output += (arr[i] % mod);
        output %= mod;
    }

    return output % mod;
}

int main() {
    string str;
    cin >> str;
    int t;
    cin >> t;
    int lengthOutput = lengthAfterTransformations(str, t);
    cout << lengthOutput << endl;
    return 0;
}