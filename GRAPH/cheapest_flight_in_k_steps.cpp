class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &connections:flights)
        {
            adj[connections[0]].push_back({connections[1],connections[2]});
        }
        queue<pair<int,pair<int,int>>>q; //(node,weight,stops)
        vector<int>dist(n,1e9);
        dist[src]=0;
        q.push({src,{0,-1}});

        while(!q.empty())
        {
            auto curr=q.front();
            int node=curr.first;
            int cost=curr.second.first;
            int stops=curr.second.second;
            q.pop();

            for(auto &it:adj[node])
            {
                int next=it.first;
                int price=it.second;
                if(cost+price<dist[next] && stops+1<=k)
                {
                    dist[next]=cost+price;
                    q.push({next,{dist[next],stops+1}});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];        
    }
};