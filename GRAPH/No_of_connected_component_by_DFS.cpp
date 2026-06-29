class Solution 
{
private:
    void DFS(int node,vector<vector<int>> &adj,vector<int> &visited)
    {
        visited[node]=1;
        for(auto it:adj[node])
        {
            if(!visited[it])
            {
                DFS(it,adj,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int V=isConnected.size();
        vector<vector<int>>adj(V);
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int>visited(V,0);
        int ans=0;
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                ans++;
                DFS(i,adj,visited);
            }
        }
        return ans;
    }
};