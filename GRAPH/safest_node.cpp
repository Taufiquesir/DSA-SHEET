class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        int n=graph.size();
        vector<vector<int>>adj(n);
        vector<int>indeg(n,0);
        vector<int>ans;
        for(int u=0;u<n;u++)
        {
            for(auto v:graph[u])
            {
                adj[v].push_back(u);
                indeg[u]++;
            }
        }

        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indeg[i]==0) q.push(i);
        }

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:adj[node])
            {
                indeg[it]--;
                if(indeg[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }        
};