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
class Solution 
{
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int V=isConnected.size();
        DSU dsu(V);
        for(int i=0;i<V;i++)
        {
            for(int j=i+1;j<V;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    dsu.unite(i,j);
                }
            }
        }
        int number_of_provinces=0;
        for(int i=0;i<V;i++)
        {
            if(dsu.findUpar(i)==i) number_of_provinces++;
        }
        return number_of_provinces;
    }
};