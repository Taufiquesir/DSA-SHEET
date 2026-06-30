class Solution {
  public:
    bool BFS(vector<vector<int>>& adj,vector<bool> &visited,int start)
    {
        queue<pair<int,int>> q;
        visited[start]=true;
        q.push({start,-1});
        
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    visited[it]=true;
                    q.push({it,node});
                }
                else if(it!=parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) 
    {
        // Code here
        vector<vector<int>> adj(V);
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
                if(BFS(adj,visited,i)) return true;
            }
        }
        return false;
    }
};