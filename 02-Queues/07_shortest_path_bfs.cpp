
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cout << "Enter vertices and edges: ";
    cin >> n >> m;

    if (n <= 0 || m < 0) {
        cout << "Invalid graph size\n";
        return 0;
    }

    vector<vector<int>> adj(n);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= n || v < 0 || v >= n) {
            cout << "Invalid vertex\n";
            return 0;
        }

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int source, destination;
    cout << "Enter source and destination: ";
    cin >> source >> destination;

    if (source < 0 || source >= n ||
        destination < 0 || destination >= n) {
        cout << "Invalid source or destination\n";
        return 0;
    }

    vector<int> distance(n, -1), parent(n, -1);
    queue<int> q;

    distance[source] = 0;
    q.push(source);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    if (distance[destination] == -1) {
        cout << "No path exists\n";
        return 0;
    }

    vector<int> path;
    for (int v = destination; v != -1; v = parent[v])
        path.push_back(v);

    reverse(path.begin(), path.end());

    cout << "Shortest distance: " << distance[destination] << '\n';
    cout << "Path: ";
    for (int v : path)
        cout << v << " ";
    cout << '\n';

    return 0;
}
