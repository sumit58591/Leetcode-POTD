#include <bits/stdc++.h>
using namespace std;

vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> output;
    unordered_map<int, int> mp;
    for(int i = 0; i < digits.size(); i++) mp[digits[i]]++;
    for(int i = 100; i < 999; i++) {
        if(i % 2 != 0) continue;
        unordered_map<int, int> tempMp;
        int temp = i;
        while(temp > 0) {
            int currLastDigit = temp % 10;
            tempMp[currLastDigit]++;
            temp /= 10;
        }

        temp = i;
        bool flag = true;
        while(temp > 0) {
            int currLastDigit = temp % 10;
            if(tempMp[currLastDigit] > mp[currLastDigit]) {
                flag = false;
                break;
            }
            temp /= 10;
        }

        if(flag) output.push_back(i);
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    vector<int> digits(n);
    for(int i = 0; i < n; i++) cin >> digits[i];
    vector<int> output = findEvenNumbers(digits);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;  
}