class Solution {
  public:
    bool DFS(int node,vector<vector<int>>& adj,vector<int>& vis,vector<int>& pathvis, vector<int>& ans)
    {
        vis[node]=1;
        pathvis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                if(DFS(it,adj,vis,pathvis,ans)==true) return true;
            }
            else if(pathvis[it]) return true;
        }
        pathvis[node]=0;
        ans.push_back(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        // code here
        vector<vector<int>>adj(numCourses);
        for(auto &course:prerequisites)
        {
            int u=course[0];
            int v=course[1];
            adj[v].push_back(u);
        }
        vector<int>vis(numCourses,0);
        vector<int>pathvis(numCourses,0);
        vector<int> ans;
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(DFS(i,adj,vis,pathvis,ans)==true) return {};
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};