// Leetcode 802
#include<bits/stdc++.h>
using namespace std;

bool dfsCycleCheck(int node, vector<vector<int>>& graph, vector<bool>& visited, 
vector<bool>& pathVisited, vector<int>& checked) {
    visited[node] = true;
    pathVisited[node] = true;
    checked[node] = 0;

    for(auto it : graph[node]) {
        if(!visited[it]) {
            if(dfsCycleCheck(it, graph, visited, pathVisited, checked)) return true;
        } else if(pathVisited[it]) return true;
    }

    checked[node] = 1;
    pathVisited[node] = 0;
    return false;
}

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int graphSize = graph.size();
    vector<bool> visited(graphSize, false);
    vector<bool> pathVisited(graphSize, false);
    vector<int> checked(graphSize, 0);
    for(int i = 0; i < graphSize; i++) {
        if(!visited[i]) {
            dfsCycleCheck(i, graph, visited, pathVisited, checked);
        }
    }

    vector<int> safeNodes;
    for(int i = 0; i < graphSize; i++) if(checked[i]) safeNodes.push_back(i);
    return safeNodes;
}

int main () {
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    vector<int> result = eventualSafeNodes(graph);
    for (int node : result) {
        cout << node << " ";
    }
    return 0;
}
// Done