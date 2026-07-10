class DSU {
    public:
    vector<int> parent,rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    int findUpar(int x)
    {
        if(parent[x]==x) return x;
        return parent[x]=findUpar(parent[x]);
    }

    void unite(int x,int y)
    {
        x=findUpar(x);
        y=findUpar(y);

        if(x==y) return;
        if(rank[x]<rank[y]) parent[x]=y;
        else if (rank[x]>rank[y]) parent[y]=x;
        else
        {
            parent[y]=x;
            rank[x]++;
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        DSU dsu(n);
        int extra_edges=0;
        int No_of_components=0;
        for(auto &connection:connections)
        {
            int u=connection[0];
            int v=connection[1];
            if(dsu.findUpar(u)==dsu.findUpar(v))
            {
                extra_edges++;
            }
            else
            {
                dsu.unite(u,v);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dsu.findUpar(i)==i) No_of_components++;
        }
        if(extra_edges>=(No_of_components-1)) return No_of_components-1;
        return -1;        
    }
};