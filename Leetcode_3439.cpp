#include <bits/stdc++.h>
using namespace std;

int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    vector<int> gaps;
    gaps.push_back(startTime[0]);
    for(int i = 1; i < startTime.size(); i++) {
        gaps.push_back(startTime[i] - endTime[i - 1]);
    }

    gaps.push_back(eventTime - endTime[endTime.size() - 1]);
    int i = 0, j = 0, maxFreeTimeOutput = 0;
    int currMaxFreeTime = 0;
    while(j < gaps.size()) {
        currMaxFreeTime += gaps[j];
        while(j - i + 1 > k + 1) {
            currMaxFreeTime -= gaps[i];
            i++;
        }

        maxFreeTimeOutput = max(maxFreeTimeOutput, currMaxFreeTime);
        j++;
    }

    return maxFreeTimeOutput;
}

int main() {
    int n;
    cin >> n;
    vector<int> startTime(n), endTime(n);
    for(int i = 0; i < n; i++) cin >> startTime[i];
    for(int i = 0; i < n; i++) cin >> endTime[i];
    int eventTime, k;
    cin >> eventTime >> k;
    int maxFreeTimeOutput = maxFreeTime(eventTime, k, startTime, endTime);
    cout << maxFreeTimeOutput << endl; 
    return 0;
}