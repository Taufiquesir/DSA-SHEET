class Solution {
  public:
    void DFS(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis,vector<pair<int,int>>& vec,int brow,int bcol)
    {
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=true;
        vec.push_back({i-brow,j-bcol});
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        for(int k=0;k<4;k++)
        {
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[nr][nc]=='L')
            {
                DFS(nr,nc,grid,vis,vec,brow,bcol);
            }
        }
    }
    int countDistinctIslands(vector<vector<char>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,false));
        set<vector<pair<int,int>>>st;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]=='L')
                {
                    vector<pair<int,int>>vec;
                    DFS(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};
