class DSU 
{ 
  private:
      vector<int> parent,rank;
  public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        
        for(int i=0;i<n;i++) 
           parent[i]=i;
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
        else if(rank[x]>rank[y]) parent[y]=x;
        else
        {
            parent[x]=y;
            rank[y]++;
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) 
    {
        DSU dsu(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int count=0;
        vector<int>ans;
        for(auto it:operators)
        {
            int row=it[0];
            int col=it[1];
            
            if(vis[row][col]==1)
            {
                ans.push_back(count);
                continue;
            }
            vis[row][col]=1;
            count++;
            int dr[4]={-1,0,1,0};
            int dc[4]={0,-1,0,1};
            
            for(int i=0;i<4;i++)
            {
                int adjr=row+dr[i];
                int adjc=col+dc[i];
                
                if(adjr>=0 && adjr<n && adjc>=0 && adjc<m && vis[adjr][adjc]==1)
                {
                    int nodeNo = row * m + col;
                    int adjNodeNo = adjr * m + adjc;
                    if(dsu.findUpar(nodeNo)!=dsu.findUpar(adjNodeNo))
                    {
                        count--;
                        dsu.unite(nodeNo,adjNodeNo);
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
