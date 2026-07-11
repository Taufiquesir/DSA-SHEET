class DSU
{
private:
    vector<int>parent,size;
public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n,1);
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
        if(size[x]<size[y])
        {
            parent[x]=y;
            size[y]+=size[x];
        }
        else
        {
            parent[y]=x;
            size[x]+=size[y];
        }
    }    
    int getSize(int node)
    {
        return size[findUpar(node)];
    }
};
class Solution 
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        DSU dsu(n*n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0) continue;
                int dr[4]={-1,0,1,0};
                int dc[4]={0,-1,0,1};
                for(int k=0;k<4;k++)
                {
                    int newr=i+dr[k];
                    int newc=j+dc[k];
                    if(newr>=0 && newc>=0 && newr<n && newc<n && grid[newr][newc]==1)
                    {
                        int nodeNo=i*n+j;
                        int adjNodeNo=newr*n+newc;
                        dsu.unite(nodeNo,adjNodeNo);
                    }
                }
            }
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) continue;
                int dr[4]={-1,0,1,0};
                int dc[4]={0,-1,0,1};
                set<int>component;
                for(int k=0;k<4;k++)
                {
                    int newr=i+dr[k];
                    int newc=j+dc[k];
                    if(newr>=0 && newc>=0 && newr<n && newc<n && grid[newr][newc]==1)
                    {
                        int nodeNo=i*n+j;
                        int adjNodeNo=newr*n+newc;
                        component.insert(dsu.findUpar(adjNodeNo));
                    }
                }
                int size_total=1;
                for(auto it:component)
                {
                    size_total+=dsu.getSize(it);
                }
                mx=max(mx,size_total);
            }
        }
         // Step 3: Handle the case when the grid is all 1s
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    mx = max(mx, dsu.getSize(i * n + j));
                }
            }
        }
        return mx;
    }
};