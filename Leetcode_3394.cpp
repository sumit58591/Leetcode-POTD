#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> buildAndMergeOpen(vector<vector<int>>& rectangles, bool vertical) {
    vector<vector<int>> intervals;
    for(const auto& rectangle : rectangles) {
        intervals.push_back(vertical ? vector<int> {rectangle[0], rectangle[2]} : vector<int> {rectangle[1], rectangle[3]});
    }

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> mergedIntervals;
    vector<int> current = intervals[0];
    for(int i = 1; i < intervals.size(); i++) {
        vector<int>& next = intervals[i];
        if(current[1] > next[0]) {
            current[1] = max(next[1], current[1]);
        } else {
            mergedIntervals.push_back(current);
            current = next;
        }
    }

    mergedIntervals.push_back(current);
    return mergedIntervals;
}

bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    vector<vector<int>> mergedX = buildAndMergeOpen(rectangles, true);
    if(mergedX.size() >= 3) return true;
    vector<vector<int>> mergedY = buildAndMergeOpen(rectangles, false);
    if(mergedY.size() >= 3) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    int numOfRectangles;
    cin >> numOfRectangles;
    vector<vector<int>> rectangles(numOfRectangles, vector<int>(4));
    for(int i = 0; i < numOfRectangles; i++) {
        for(int j = 0; j < 4; j++) cin >> rectangles[i][j];
    }

    bool output = checkValidCuts(n, rectangles);
    if(output) cout << "true" << endl;
    else cout << "false" << endl;
    return 0;
}