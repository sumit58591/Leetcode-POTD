// Leetcode 2493
#include<bits/stdc++.h>
using namespace std;

vector<int> graph[505];
int color[505];
vector<int> connectedComponents;
bool isBipartite;

int maximumDistanceFromNode(int node, int totalNode) {
    vector<int> distance(totalNode + 1, -1);
    queue<int> q;
    q.push(node);
    distance[node] = 1;
    int maxDistance = 1;

    while(!q.empty()) {
        int currentNode = q.front();
        q.pop();

        for(auto &neighbour : graph[currentNode]) {
            if(distance[neighbour] == -1) {
                distance[neighbour] = distance[currentNode] + 1;
                q.push(neighbour);
                maxDistance = max(maxDistance, distance[neighbour]);
            }
        }
    }

    return maxDistance;
}

void dfs(int node, int currentColor = 1) {
    color[node] = currentColor;
    connectedComponents.push_back(node);

    for(auto &neighbour : graph[node]) {
        if(color[neighbour] == 0) {
            dfs(neighbour, 3 - currentColor);
        } else if(color[neighbour] == currentColor) isBipartite = false;
    }
}

int magnificentSets(int n, vector<vector<int>>& edges) {
    for(int i = 0; i <= n; i++) graph[i].clear();
    memset(color, 0, sizeof color);

    for(auto &edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    int maxGroups = 0;
    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) {
            connectedComponents.clear();
            isBipartite = true;
            
            dfs(i);
            if(!isBipartite) return -1;

            int maxDistance = 0;
            for(auto &node: connectedComponents) {
                maxDistance = max(maxDistance, maximumDistanceFromNode(node, n));
            }
            maxGroups += maxDistance;
        }
    }

    return maxGroups;
}

int main () {

}