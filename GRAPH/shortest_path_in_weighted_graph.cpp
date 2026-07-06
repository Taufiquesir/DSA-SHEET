class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) 
    {
        // Code here
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &e:edges)
        {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1);
        for(int i=1;i<n+1;i++)
        {
            parent[i]=i;
        }
        dist[1]=0;
        pq.push({0,1});
        
        while(!pq.empty())
        {
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(dis > dist[node]) continue;
            
            for(auto it:adj[node])
            {
                int adj_node=it.first;
                int edge_wt=it.second;
                
                if(dis+edge_wt<dist[adj_node])
                {
                    dist[adj_node]=dis+edge_wt;
                    pq.push({dist[adj_node],adj_node});
                    parent[adj_node]=node;
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        vector<int>path;
        int node=n;
        while(parent[node]!=node)
        {
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        path.insert(path.begin(),dist[n]);
        return path;
    }
};