class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));
        for(auto &e:edges)
            {
                int u=e[0];
                int v=e[1];
                int wt=e[2];
                dist[u][v]=wt;
                dist[v][u]=wt;
            }
        for(int i=0;i<n;i++) dist[i][i]=0;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]==INT_MAX ||dist[k][j]==INT_MAX) continue;
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        int cntcity=INT_MAX;
        int cityNo=-1;
        for(int city=0;city<n;city++)
        {
            int cnt=0;
            for(int adjcity=0;adjcity<n;adjcity++)
            {
                if(dist[city][adjcity]<=distanceThreshold)
                   cnt++;
            }
            if(cnt<=cntcity)
            {
                cntcity=cnt;
                cityNo=city;
            }
        }
        return cityNo;
    }
};