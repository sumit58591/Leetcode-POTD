#include <bits/stdc++.h>
using namespace std;

vector<string> divideString(string s, int k, char fill) {
    string str = s;
    if(str.size() % k != 0) {
        while(str.size() % k != 0) {
            str += fill;
        }
    }

    int i = 0, j = 0;
    vector<string> output;
    for(int i = 0; i < str.size(); i++) {
        int count = 0;
        string temp = "";
        while(count < k) {
            temp += str[j++];
            count++;
        }

        output.push_back(temp);
        i = j - 1;
    }

    return output;
}

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    char fill;
    cin >> fill;
    vector<string> output = divideString(s, k, fill);
    for(int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }

    return 0;
}