#include <bits/stdc++.h>
using namespace std;

long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long sum1 = 0, sum2 = 0, zeroCount1 = 0, zeroCount2 = 0;
    for(int i = 0; i < nums1.size(); i++) {
        if(nums1[i] == 0) {
            zeroCount1++;
            sum1++;
        } else sum1 += (long long) nums1[i];
    }

    for(int i = 0; i < nums2.size(); i++) {
        if(nums2[i] == 0) {
            zeroCount2++;
            sum2++;
        } else sum2 += (long long) nums2[i];
    }

    if(sum1 < sum2 and zeroCount1 == 0) return -1;
    else if(sum2 < sum1 and zeroCount2 == 0) return -1;
    else return max(sum1, sum2);
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> arr1(m), arr2(n);
    for(int i = 0; i < m; i++) cin >> arr1[i];
    for(int i = 0; i < n; i++) cin >> arr2[i];
    long long output = minSum(arr1, arr2);
    cout << output << endl;
    return 0;
}