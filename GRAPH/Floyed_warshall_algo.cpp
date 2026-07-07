class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) 
    {
        // Code here
        int v=dist.size();
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(dist[i][j]==-1)
                {
                    dist[i][j]=1e8;
                }
                if(i==j) dist[i][j]=0;
            }
        }
        for(int k=0;k<v;k++)
        {
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<v;j++)
                {
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        for(int i=0;i<v;i++)
        {
            for(int j=0;j<v;j++)
            {
                if(dist[i][j]==1e8)
                {
                    dist[i][j]=-1;
                }
            }
        }
        
    }
};