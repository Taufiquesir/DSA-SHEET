class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // pair<distance,node>
        vector<vector<pair<int,int>>>adj(V);
        for(auto &e:edges)
        {
            int u=e[0];
            int v=e[1];
            int wt=e[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        set<pair<int,int>>st;
        vector<int>dist(V,1e9);
        dist[src]=0;
        st.insert({0,src});
        
        while(!st.empty())
        {
            auto it=*(st.begin());
            int dis=it.first;
            int node=it.second;
            st.erase(it);
            
            for(auto it:adj[node])
            {
                int adj_node=it.first;
                int edge_wt=it.second;
                if(dis+edge_wt<dist[adj_node])
                {
                    if(dist[adj_node]!=1e9) //someone reached
                       st.erase({dist[adj_node],adj_node});
                    dist[adj_node]=dis+edge_wt;
                    st.insert({dist[adj_node],adj_node});
                }
            }
        }
        return dist;
    }
};