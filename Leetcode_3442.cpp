#include <bits/stdc++.h>
using namespace std;

int maxDifference(string s) {
    int arr[256] = {0};
    for(int i = 0; i < s.length(); i++) arr[s[i]]++;
    int maxOddFreq = 0, minOddFreq = s.length(), maxEvenFreq = 0, minEvenFreq = s.length();
    for(int i = 0; i < 256; i++) {
        if(arr[i]) {
            if(arr[i] % 2 == 0) {
                minEvenFreq = min(minEvenFreq, arr[i]);
            } else {
                maxOddFreq = max(maxOddFreq, arr[i]);
            }
        }
    }

    return maxOddFreq - minEvenFreq;
}

int main() {
    string s;
    cin >> s;
    int output = maxDifference(s);
    cout << output << endl;
    return 0;
}