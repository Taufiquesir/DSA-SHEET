class Solution 
{
  public:
    
    void BFS_traversal(int start,vector<vector<int>>& adj,vector<int> &visited)
    {
        queue<int>q;
        visited[start]=1;
        q.push(start);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int countConnected(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans;
        vector<int>visited(V,0);
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                ans++;
                BFS_traversal(i,adj,visited);
            }
        }
        return ans;
    }
};
