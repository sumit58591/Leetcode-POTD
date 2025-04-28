#include <bits/stdc++.h>
using namespace std;

long long countSubarrays(vector<int>& nums, long long k) {
    int i = 0, j = 0, n = nums.size();
    long long countOutput = 0, currSum = 0, score = 0;
    int currLength = 0;
    while(j < n) {
        currLength = j - i + 1;
        currSum += nums[j];
        score = currSum * currLength;
        while(score >= k) {
            currSum -= nums[i];
            i++;
            currLength = j - i + 1;
            score = currSum * currLength;
        }

        countOutput += (long long)(j - i + 1);
        j++;
    }

    return countOutput;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    long long k;
    cin >> k;
    long long countOutput = countSubarrays(arr, k);
    cout << countOutput << endl;
    return 0;
}