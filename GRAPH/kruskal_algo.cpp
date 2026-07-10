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
        return parent[x]=findUpar(parent[x]);  //path compression
    }
    void unite(int x,int y)
    {
        x=findUpar(x);
        y=findUpar(y);

        if(x==y) return;
        if(rank[x]<rank[y]) parent[x]=y;
        else if(rank[y]<rank[x]) parent[y]=x;
        else 
        {
            parent[y]=x;
            rank[x]++;            
        }
    }
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) 
    {
        // code here
        sort(edges.begin(),edges.end(),
        [](vector<int> &a,vector<int> &b)
        {
            return a[2]<b[2];
        });
        
        DSU dsu(V);
        int mst_cost=0;
        
        for(auto &e:edges)
        {
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            
            if(dsu.findUpar(u)!=dsu.findUpar(v))
            {
                mst_cost+=wt;
                dsu.unite(u,v);
            }
        }
        return mst_cost;
    }
};