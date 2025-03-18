// Leetcode 1910
#include <bits/stdc++.h>
using namespace std;

string removeOccurrences(string s, string part) {
    string output = "";
    int n = s.length(), partLength = part.length();
    for(int i = 0; i < n; i++) {
        output += s[i];
        if((output.length() >= partLength) and (output.substr(output.length() - partLength) == part)) {
            output.erase(output.length() - partLength);
        }
    }

    return output;
}

int main() {
    string s, part;
    cin >> s >> part;
    string output = removeOccurrences(s, part);
    cout << output << endl;
}