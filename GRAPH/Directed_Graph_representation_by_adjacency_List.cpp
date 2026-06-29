#include<bits/stdc++.h>
using namespace std;

int main()
{
    int vertex,edges;
    cout<<"Enter the number of vertex and Edges: ";
    cin>>vertex>>edges;
    vector<int>adj[vertex+1];
    while(edges--)
    {
        int u,v;
        cout<<"Enter the edges: ";
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=vertex;i++)
    {
        cout<<"Vertex "<<i<<": ";
        for(int j=0;j<adj[i].size();j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}