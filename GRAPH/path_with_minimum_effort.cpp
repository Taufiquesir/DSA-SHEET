class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        int m=heights.size();
        int n=heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(m,vector<int>(n,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});

        int dr[4]={0,0,-1,1};
        int dc[4]={-1,1,0,0};

        while(!pq.empty())
        {
            int diff=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==m-1 && j==n-1) return diff;

            for(int k=0;k<4;k++)
            {
                int nr=i+dr[k];
                int nc=j+dc[k];

                if(nr>=0 && nc>=0 && nr<m && nc<n)
                {
                    int new_effort=max(diff,abs(heights[i][j]-heights[nr][nc]));
                    if(new_effort<dist[nr][nc])
                    {
                        dist[nr][nc]=new_effort;
                        pq.push({new_effort,{nr,nc}});
                    }
                }
            }
        }
        return 0;        
    }
};