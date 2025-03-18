// Leetcode 2523
#include <bits/stdc++.h>
using namespace std;

bool checkPrime(int n) {
    if(n < 2) return false;
    int sqrt_of_n = sqrt(n);
    for(int i = 2; i <= sqrt_of_n; i++) if(n % i == 0) return false;
    return true;
}

vector<int> closestPrimes(int left, int right) {
    vector<int> primeNumbers;
    for(int i = left; i <= right; i++) {
        if(checkPrime(i)) primeNumbers.push_back(i);
    }

    if(primeNumbers.size() < 2) return {-1, -1};
    int minDiff = INT_MAX;
    int firstOutput = primeNumbers[0], secondOutput = primeNumbers[1];
    for(int i = 1; i < primeNumbers.size(); i++) {
        int currDiff = primeNumbers[i] - primeNumbers[i - 1];
        if(currDiff < minDiff) {
            minDiff = min(currDiff, minDiff);
            firstOutput = primeNumbers[i - 1];
            secondOutput = primeNumbers[i];
        }
    }

    return {firstOutput, secondOutput};
}

int main() {
    int left, right;
    cin >> left >> right;
    vector<int> output = closestPrimes(left, right);
    for(int i = 0; i < output.size(); i++) cout << output[i] << " ";
    return 0;
}