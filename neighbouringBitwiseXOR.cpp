// Leetcode 2683
#include<iostream>
#include<vector>
using namespace std;

bool doesValidArrayExist(vector<int>& derived) {
    int n = derived.size();
    vector<int> original(n, 0);
    for(int i = 0; i <= 1; i++) {
        original[0] = i;
        for(int i = 1; i < n; i++) {
            original[i] = derived[i - 1] ^ original[i - 1];
        }

        if(original[0] ^ original[n - 1] == derived[n - 1]) return true;
    }

    return false;
}

int main () {
    int n;
    cin >> n;
    vector<int> derived(n);
    for(int i = 0; i < n ; i++) cin >> derived[i];
    bool output = doesValidArrayExist(derived);
    if(output) cout << "True" << endl;
    else cout << "False" << endl;
    return 0;
}