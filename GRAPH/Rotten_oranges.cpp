// we will apply multi source bfs to find the time taken to rot all oranges

// Queue<pair<int,int>,int>q; <node,time>

class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) 
    {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        int ans=0;
        
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>>q;    // <node(i,j),time>
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==2)
                {
                    q.push({{i,j},0});
                    visited[i][j]=true;
                }
            }
        }
        
        // Apply BFS
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            int i=node.first.first;
            int j=node.first.second;
            int time=node.second;
            
            ans=max(ans,time);
            
            if(i-1>=0 && !visited[i-1][j] && mat[i-1][j]==1) //top
            {
                visited[i-1][j]=true;
                q.push({{i-1,j},time+1});
                mat[i-1][j]=2;
            }
            if(i+1<n && !visited[i+1][j] && mat[i+1][j]==1) //down
            {
                visited[i+1][j]=true;
                q.push({{i+1,j},time+1});
                mat[i+1][j]=2;
            }
            if(j-1>=0 && !visited[i][j-1] && mat[i][j-1]==1) //left
            {
                visited[i][j-1]=true;
                q.push({{i,j-1},time+1});
                mat[i][j-1]=2;
            }
            if(j+1<m && !visited[i][j+1] && mat[i][j+1]==1) //right
            {
                visited[i][j+1]=true;
                q.push({{i,j+1},time+1});
                mat[i][j+1]=2;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return ans;
    }
};