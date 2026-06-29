#include <bits/stdc++.h>
using namespace std;

void DFS_traversal(int node, vector<int> adj[], int visited[], vector<int> &result)
{
    visited[node] = 1;
    result.push_back(node);
    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            DFS_traversal(it, adj, visited, result);
        }
    }
}

int main()
{
    int vertex, edges;

    cout << "Enter the number of vertices and edges: ";
    cin >> vertex >> edges;

    vector<int> adj[vertex + 1];

    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cout << "Enter the edge: ";
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int visited[vertex + 1] = {0};
    vector<int> result;
    int start = 0; // Starting node for DFS traversal

    DFS_traversal(start, adj, visited, result);

    cout << "DFS Traversal: ";

    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}