#include <bits/stdc++.h>
using namespace std;

string kthCharacter_helper(string str, int k) {
    if(str.length() >= k) return str;
    string temp = "";
    for(int i = 0; i < str.length(); i++) {

        if(str[i] == 'z') temp += 'a';
        else temp += (str[i] + 1);
    }

    return kthCharacter_helper(str + temp, k);
}

char kthCharacter(int k) {
    string str = "a";
    string newStr = kthCharacter_helper(str, k);
    return newStr[k - 1];
}

int main() {
    int k;
    cin >> k;
    char output = kthCharacter(k);
    cout << output << endl;
    return 0;
}