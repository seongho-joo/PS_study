/**
 * https://www.acmicpc.net/problem/1260
 * BOJ1260 - DFS와 BFS
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int> > graph;
vector<bool> visited;

void DFS(int s) {
    visited[s] = true;
    cout << s << " ";
    for (int i = 0; i < graph[s].size(); i++) {
        int next = graph[s][i];
        if (!visited[next]) DFS(next);
    }
}

void BFS(int s) {
    queue<int> q;
    visited[s] = true;
    q.push(s);
    cout << "\n" << s << ' ';
    while (!q.empty()) {
        int cur = q.front();
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (!visited[next]) {
                cout << next << ' ';
                visited[next] = true;
                q.push(next);
            }
        }
        q.pop();
    }
}

int main() {
    ifstream inp("fcfs.inp");
    int N, M, V;
    cin >> N >> M >> V;

    graph.resize(N + 1);
    visited.resize(N + 1);

    while (M--) {
        int i, j;
        cin >> i >> j;
        graph[i].push_back(j);
        graph[j].push_back(i);
    }

    for (int i = 1; i <= N; i++) sort(graph[i].begin(), graph[i].end());

    DFS(V);
    visited.clear();
    visited.resize(N + 1, false);
    BFS(V);

    return 0;
}