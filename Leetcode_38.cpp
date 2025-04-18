#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
    if(n == 1) {
        return "1";
    }

    string smallOutput = countAndSay(n - 1);
    string output = "";
    for(int i = 0; i < smallOutput.size(); i++) {
        int startIndex = i + 1, count = 1;
        while(startIndex < smallOutput.size() and smallOutput[i] == smallOutput[startIndex]) {
            startIndex++;
            count++;
        }

        output += to_string(count);
        output += smallOutput[i];
        i = startIndex - 1;
    }

    return output;
}

int main() {
    int n;
    cin >> n;
    string output = countAndSay(n);
    cout << output << endl;
    return 0;
}