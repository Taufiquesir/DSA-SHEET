class Solution 
{
  public:
    
    void BFS_traversal(int start,vector<vector<int>>& adj,vector<int> &visited,vector<vector<int>> &ans)
    {
        vector<int>temp;
        queue<int>q;
        visited[start]=1;
        q.push(start);
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            temp.push_back(node);
            for(auto it:adj[node])
            {
                if(!visited[it])
                {
                    visited[it]=1;
                    q.push(it);
                }
            }
        }
        ans.push_back(temp);
    }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>> adj(V);
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(V,0);
        vector<vector<int>>ans;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                BFS_traversal(i,adj,visited,ans);
            }
        }
        return ans;
    }
};
