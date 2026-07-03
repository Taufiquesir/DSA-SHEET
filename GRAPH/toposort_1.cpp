class Solution {
  public:
  
void topo(int vertex, vector<vector<int>> &adj, vector<int> &visited, vector<int> &indeg,vector<int>&topo_ans)
{
    queue<int> q;
    for (int i = 0; i < vertex; i++)
    {
        if (indeg[i] == 0)
        {
            q.push(i);
        }
    }
    while ((!q.empty()))
    {
        int node = q.front();
        topo_ans.push_back(node);
        q.pop();
        for (int j = 0; j < adj[node].size(); j++)
        {
            indeg[adj[node][j]]--;
            if (indeg[adj[node][j]] == 0)
            {
                q.push(adj[node][j]);
            }
        }
    }
    
}
    vector<int> topoSort(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(V);
        vector<int>visited(V,0);
        vector<int>indeg(V,0);
        vector<int>topo_ans;
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            indeg[v]++;
        }
        topo(V,adj,visited,indeg,topo_ans);
        return topo_ans;
    }
};