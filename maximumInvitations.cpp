// Leetcode 2127
#include<bits/stdc++.h>
using namespace std;
int maximumInvitations(vector<int>& favorite) {
    int n = favorite.size();
    vector<int> inDegree(n, 0), depth(n, 1);
    for(int person = 0; person < n; person++) inDegree[favorite[person]]++;
    queue<int> q;
    for(int person = 0; person < n; person++) if(inDegree[person] == 0) q.push(person);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        int next = favorite[curr];
        depth[next] = max(depth[curr] + 1, depth[next]);
        if(--inDegree[next] == 0) q.push(next);
    }

    int twoCycleInvitations = 0, maxInvitation = 0;
    for(int person = 0; person < n; person++) {
        int curr = person, currCycleLength = 0;
        while(inDegree[curr] != 0) {
            inDegree[curr] = 0;
            currCycleLength++;
            curr = favorite[curr];
        }

        if(currCycleLength == 2) {
            twoCycleInvitations += depth[person] + depth[favorite[person]];
        } else maxInvitation = max(maxInvitation, currCycleLength);
    }

    return max(twoCycleInvitations, maxInvitation);
}

int main () {
    int n;
    cin >> n;
    vector<int> favorite(n);
    for(int i = 0; i < n; i++) cin >> favorite[i];
    int output = maximumInvitations(favorite);
    cout << output << endl;
    return 0;
}

// Done