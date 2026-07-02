class Solution {
public:
    int cntOnes(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,false));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0||j==0||i==n-1||j==m-1)
                {
                    if(grid[i][j]==1)
                    {
                        q.push({i,j});
                        vis[i][j]=true;
                    }
                }
            }
        }
        
        int dr[4]={-1,1,0,0};
        int dc[4]={0,0,-1,1};
        
        while(!q.empty())
        {
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int nr=i+dr[k];
                int nc=j+dc[k];
                if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]==1)
                {
                    q.push({nr,nc});
                    vis[nr][nc]=true;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1) ans++;
            }
        }
        return ans;
    }
};