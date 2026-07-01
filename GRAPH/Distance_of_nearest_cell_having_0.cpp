class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        while(!q.empty())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            if(i-1>=0 && !visited[i-1][j] && mat[i-1][j]==1)
            {
                ans[i-1][j]=dist+1;
                q.push({{i-1,j},dist+1});
                visited[i-1][j]=true;

            }
            if(i+1<m && !visited[i+1][j] && mat[i+1][j]==1)
            {
                ans[i+1][j]=dist+1;
                q.push({{i+1,j},dist+1});
                visited[i+1][j]=true;
            }
            if(j-1>=0 && !visited[i][j-1] && mat[i][j-1]==1)
            {
                ans[i][j-1]=dist+1;
                q.push({{i,j-1},dist+1});
                visited[i][j-1]=true;
            }
            if(j+1<n && !visited[i][j+1] && mat[i][j+1]==1)
            {
                ans[i][j+1]=dist+1;
                q.push({{i,j+1},dist+1});
                visited[i][j+1]=true;
            }
        }
        return ans;        
    }
};