class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat, vector<int> &src, vector<int> &dest) 
    {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        
        if(mat[src[0]][src[1]]==0||mat[dest[0]][dest[1]]==0) return -1;
        if(src==dest) return 0;
        
        queue<pair<int,pair<int,int>>>q;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[src[0]][src[1]]=0;
        q.push({0,{src[0],src[1]}});
        
        int dr[4]={0,0,-1,1};
        int dc[4]={-1,1,0,0};
        
        while(!q.empty())
        {
            int dis=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            
            for(int k=0;k<4;k++)
            {
                int nr=i+dr[k];
                int nc=j+dc[k];
                
                if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]==1)
                {
                    if(dis+1<dist[nr][nc])
                    {
                        dist[nr][nc]=dis+1;
                        if(nr==dest[0] && nc==dest[1]) return dis+1;
                        q.push({dis+1,{nr,nc}});
                    }
                }
            }
        }
        return -1;
    }
};
