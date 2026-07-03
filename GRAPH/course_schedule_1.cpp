class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<vector<int>>adj(numCourses);
        vector<int>indeg(numCourses,0);
        int count=0;
        for(auto &course:prerequisites)
        {
            int u=course[0];
            int v=course[1];
            adj[v].push_back(u);
            indeg[u]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(indeg[i]==0) q.push(i);
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            for(auto it:adj[node])
            {
                indeg[it]--;
                if(indeg[it]==0)
                {
                    q.push(it);
                }
            }
        }
        return count==numCourses;
        
    }
};