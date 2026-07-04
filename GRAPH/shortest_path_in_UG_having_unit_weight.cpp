class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) 
    {
        // code here
        vector<vector<int>>adj(V);
        for(auto &e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        vector<int>dist(V,INT_MAX);
        dist[src]=0;
        q.push(src);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            if(dist[node]!=INT_MAX)
            {
                 for(auto it:adj[node])
                 {
                     if(dist[node]+1<dist[it])
                     {
                         dist[it]=dist[node]+1;
                         q.push(it);
                     }
                 }
            }
        }
        return dist[dest]==INT_MAX?-1:dist[dest];
    }
};
