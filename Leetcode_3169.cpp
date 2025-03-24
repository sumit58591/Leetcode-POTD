#include <bits/stdc++.h>
using namespace std;

int countDays(int days, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end()); 
    int last = 1, n = meetings.size();
    int output = 0;
    for(int i = 0; i < n; i++) {
        int start = meetings[i][0];
        if(start > last) output += (i == 0) ? (start - last) : (start - last - 1);

        last = max(last, meetings[i][1]);
    }

    if(days > last) output += days - last;
    return output;
}

int main() {
    int days;
    cin >> days;
    int numberOfMeetings;
    cin >> numberOfMeetings;
    vector<vector<int>> meetings(numberOfMeetings, vector<int>(2));
    for(int i = 0; i < numberOfMeetings; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> meetings[i][j];
        }
    }

    int countDaysOutput = countDays(days, meetings);
    cout << countDaysOutput << endl;
    return 0;
}