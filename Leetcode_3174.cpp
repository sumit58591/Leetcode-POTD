// Leetcode 3174
#include <bits/stdc++.h>
using namespace std;

string clearDigits(string s) {
    stack<char> st;
    int n = s.length();
    for(int i = 0; i < n; i++) {
        if(s[i] >= '0' and s[i] <= '9') {
            st.pop();
        } else st.push(s[i]);
    }

    string output = "";
    while(!st.empty()) {
        output += st.top();
        st.pop();
    }

    reverse(output.begin(), output.end());
    return output;
}

int main() {
    string input;
    cin >> input;
    string output = clearDigits(input);
    cout << output << endl;
}
