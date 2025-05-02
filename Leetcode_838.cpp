#include <bits/stdc++.h>
using namespace std;

void doubleDominoesPush(string &output, int start, int end) {
    while(start < end) {
        output[start++] = 'R';
        output[end--] = 'L';
    }
}

void leftDominoesPush(string &output, int start, int end) {
    while(start <= end) {
        output[start++] = 'L';
    }
}

void rightDominoesPush(string &output, int start, int end) {
    while(start <= end) {
        output[start++] = 'R';
    }
}

string pushDominoes(string dominoes) {
    int last_R = -1, last_L = -1, n = dominoes.length();
    string output = dominoes;
    for(int i = 0; i < n; i++) {
        if(dominoes[i] == 'L') {
            if(last_R > last_L) doubleDominoesPush(output, last_R, i);
            else if(last_L > last_R or last_L == -1) leftDominoesPush(output, last_L + 1, i);

            last_L = i;
        } else if(dominoes[i] == 'R') {
            if(last_R > last_L) rightDominoesPush(output, last_R, i);
            last_R = i;
        }
    }

    if(last_R > last_L) rightDominoesPush(output, last_R + 1, n - 1);
    return output;
}

int main() {
    string dominoes;
    cin >> dominoes;
    string output = pushDominoes(dominoes);
    cout << output << endl;
    return 0;
}