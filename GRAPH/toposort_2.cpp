class Solution {
  public:
  
    void DFS(int node, vector<vector<int>> &adj, vector<int> &visited,stack<int>& st)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                DFS(it,adj,visited,st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) 
    {
        vector<vector<int>>adj(V);
        vector<int>visited(V,0);
        vector<int>ans;
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
             DFS(i,adj,visited,st);
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};