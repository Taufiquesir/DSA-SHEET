#include <bits/stdc++.h>
using namespace std;

vector<int> BFS_traversal(vector<int> adj[], int start, int vertex)
{
    vector<int> result;
    vector<bool> visited(vertex + 1, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        result.push_back(node);

        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                visited[adj[node][i]] = true;
                q.push(adj[node][i]);
            }
        }
    }

    return result;
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

    vector<int> BFS_trav = BFS_traversal(adj, 1, vertex);

    cout << "BFS Traversal: ";

    for (auto it : BFS_trav)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}