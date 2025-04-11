#include <bits/stdc++.h>
using namespace std;

bool isSymmetric(int num) {
    string integer = to_string(num);
    int i = 0, integerLength = integer.size();
    int leftHalfSum = 0, rightHalfSum = 0;
    while(i < integerLength / 2) {
        leftHalfSum += integer[i++];
    }
    
    while(i < integerLength) {
        rightHalfSum += integer[i++];
    }

    return leftHalfSum == rightHalfSum;
}

int countSymmetricIntegers(int low, int high) {
    int outputCount = 0;
    for(int i = low; i <= high; i++) {
        int numOfDigits = log10(i) + 1;
        if(numOfDigits % 2 == 0 and isSymmetric(i)) outputCount++; 
    }

    return outputCount;
}

int main() {
    int low, high;
    cin >> low >> high;
    int output = countSymmetricIntegers(low, high);
    cout << output << endl;
}