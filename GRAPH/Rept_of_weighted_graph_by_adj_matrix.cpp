#include<iostream>
using namespace std;

int main()
{
    int vertex,edges;
    cout<<"Enter the number of vertex and Edges: ";
    cin>>vertex>>edges;
    int adj[vertex+1][vertex+1]={0};
    while(edges--)
    {
        int u,v,weight;
        cout<<"Enter the edge: ";
        cin>>u>>v>>weight;
        adj[u][v]=weight;
        adj[v][u]=weight;
    }
    for(int i=1;i<=vertex;i++)
    {
        for(int j=1;j<=vertex;j++)
        {
            cout<<adj[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;  
}
