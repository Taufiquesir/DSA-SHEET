class Solution 
{
private:
    int timer=1;
    void DFS(int node,int parent,vector<int> &vis,vector<vector<int>> &adj,
    int tin[],int low[],vector<vector<int>> &bridges)
    {
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto it:adj[node])
        {
            if(it==parent) continue;
            if(!vis[it])
            {
                DFS(it,node,vis,adj,tin,low,bridges);
                low[node]=min(low[it],low[node]);  

                if(low[it]>tin[node])
                {
                    bridges.push_back({it,node});
                }              
            }
            else
            {
                low[node]=min(low[it],low[node]);
            }
        }

    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) 
    {
        vector<vector<int>>adj(n);
        for(auto &e:connections)
        {
            int a=e[0];
            int b=e[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<int>vis(n,0);
        vector<vector<int>>bridges;
        int tin[n];
        int low[n];
        DFS(0,-1,vis,adj,tin,low,bridges);
        return bridges;       
    }
};