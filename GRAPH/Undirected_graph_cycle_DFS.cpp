class Solution {
  public:
    bool DFS(vector<vector<int>>& adj,vector<bool> &visited,int start,int parent)
    {
        visited[start]=true;
        for(auto it:adj[start])
        {
            if(!visited[it])
            {
                if(DFS(adj,visited,it,start)) return true;
            }
            else if(it!=parent)
            {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) 
    {
        // Code here
        vector<vector<int>> adj(V);

        // Build adjacency list
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                if(DFS(adj,visited,i,-1)) return true;
            }
        }
        return false;
    }
};