class Solution {
public:
    int dr[4]={-1,1,0,0};
    int dc[4]={0,0,-1,1};

    void DFS(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j)
    {
        int m=grid.size();
        int n=grid[0].size();
        vis[i][j]=true;
        for(int k=0;k<4;k++)
        {
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[nr][nc]==1)
            {
                DFS(grid,vis,nr,nc);
            }
        }

    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,false));
        for(int j=0;j<n;j++)
        {
            if(!vis[0][j] && grid[0][j]==1)
            {
                DFS(grid,vis,0,j);
            }
            if(!vis[m-1][j] && grid[m-1][j]==1)
            {
                DFS(grid,vis,m-1,j);
            }
        }
        for(int i=0;i<m;i++)
        {
            if(!vis[i][0] && grid[i][0]==1)
            {
                DFS(grid,vis,i,0);
            }
            if(!vis[i][n-1] && grid[i][n-1]==1)
            {
                DFS(grid,vis,i,n-1);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] && grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};