#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<vector<int>> &adj,int start,int vertex)
{
    vector<int> BFS_trav;
    vector<int> visited(vertex+1,0);
    queue<int>q;
    q.push(start);
    visited[start]=1;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        BFS_trav.push_back(node);
        for(int i=1;i<=vertex;i++)
        {
            if(adj[node][i]==1 && visited[i]==0)
            {
                q.push(i);
                visited[i]=1;
            }
        }
    }
    return BFS_trav;
}
int main()
{
    int vertex,edges;
    cout<<"Enter the number of vertex and edges:";
    cin>>vertex>>edges;
    vector<vector<int>> adj(vertex + 1, vector<int>(vertex + 1, 0));
    while(edges--)
    {
        int u,v;
        cout<<"Enter the edges:";
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
    }
    vector<int> BFS_trav=BFS(adj,0,vertex);
    cout<<"BFS Traversal:";
    for(auto it:BFS_trav)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;                                  
}