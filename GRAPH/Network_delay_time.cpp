class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)
    {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &e:times)
        {
            adj[e[0]].push_back({e[1],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty())
        {
            auto curr=pq.top();
            int dis=curr.first;
            int node=curr.second;
            pq.pop();
            if(dis>dist[node]) continue;

            for(auto &it:adj[node])
            {
                int next=it.first;
                int wt=it.second;
                if(dis+wt<dist[next])
                {
                    dist[next]=dis+wt;
                    pq.push({dist[next],next});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9) return -1;
            ans=max(ans,dist[i]);
        }     
        return ans;
    }
};