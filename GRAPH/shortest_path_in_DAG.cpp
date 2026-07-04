class Solution 
{
  private:
    void toposort(int source,stack<int> &st,vector<vector<pair<int,int>>>& adj,vector<int>& vis)
    {
        vis[source]=1;
        for(auto it:adj[source])
        {
            int v=it.first;
            if(!vis[v])
            {
                toposort(v,st,adj,vis);
            }
        }
        st.push(source);
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) 
    {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0;i<E;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        }
        vector<int>vis(V,0);
        stack<int>st;
        for(int j=0;j<V;j++)
        {
            if(!vis[j])
            {
                toposort(j,st,adj,vis);
            }
        }
        vector<int>dist(V,INT_MAX);
        dist[0]=0;
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(dist[node]!=INT_MAX)
            {
                for(auto it:adj[node])
                {
                    int v=it.first;
                    int wt=it.second;
                    if(dist[node]+wt<dist[v])
                    {
                        dist[v]=dist[node]+wt;
                    }
                }
            }
        }
        for(int k=0;k<V;k++)
        {
            if(dist[k]==INT_MAX) dist[k]=-1;
        }
        return dist;
    }
};
