class Solution {
  public:
    void DFS1(int node,vector<int> &vis,vector<vector<int>> &adj,stack<int> &st)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                DFS1(it,vis,adj,st);
            }
        }
        st.push(node);
    }
    
    void DFS3(int node,vector<int> &vis,vector<vector<int>> &adj)
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                DFS3(it,vis,adj);
            }
        }
    }
    
    int kosaraju(int V, vector<vector<int>> &edges) 
    {
        // code here
        vector<vector<int>>adj(V);
        vector<vector<int>>adjT(V);
        for(auto &e:edges)
        {
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
            adjT[v].push_back(u);
        }
        vector<int>vis(V,0);
        stack<int>st;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                DFS1(i,vis,adj,st);
            }
        }
        // Reverse the edges og given graph
        // which I have done at the time when I wa making
        //adj list from edges matrix.
        for(int i=0;i<V;i++) 
          vis[i]=0;
          
        int scc=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            
            if(!vis[node])
            {
                scc++;
                DFS3(node,vis,adjT);
            }
        }
        return scc;
    }
};