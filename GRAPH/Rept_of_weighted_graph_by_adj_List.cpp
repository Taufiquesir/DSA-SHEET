#include<bits/stdc++.h>
using namespace std;

int main()
{
    int vertex,edges;
    cout<<"Enter the number of vertex and Edges: ";
    cin>>vertex>>edges;
    vector<pair<int,int>>adj[vertex+1];
    while(edges--)
    {
        int u,v,weight;
        cout<<"Enter the edges and their weights: ";
        cin>>u>>v>>weight;
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }
    cout<<"\nAdjacency List representation of the weighted graph:\n";
    for(int i=1;i<=vertex;i++)
    {
        cout<<"Vertex "<<i<<": ";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<"("<<adj[i][j].first<<","<<adj[i][j].second<<") ";

        }
        cout<<endl;
    }
    return 0;
}