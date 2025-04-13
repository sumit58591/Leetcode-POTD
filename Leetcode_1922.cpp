#include <bits/stdc++.h>
using namespace std;

long long modPow(long long base, long long exp) {
    long long mod = 1e9 + 7;
    long long res = 1;
    while(exp > 0) {
        if(exp % 2 == 1) {
            res = (res * base) % mod;
        }

        base = (base * base) % mod;
        exp /= 2;
    }

    return res;
}

int countGoodNumbers(long long n) {
    long long mod = 1e9 + 7;
    long long evenPos = (n + 1) / 2;
    long long oddPos = (n / 2);
    long long oddChoices = modPow(4, oddPos);
    long long evenChoices = modPow(5, evenPos);
    return (oddChoices * evenChoices) % mod;
}

int main() {
    long long n;
    cin >> n;
    int output = countGoodNumbers(n);
    cout << output << endl;
    return 0;
}