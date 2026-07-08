class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) 
    {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(auto &e:edges)
        {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>visited(V,0);
        // {weight,node}
        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            auto curr=pq.top();
            pq.pop();
            
            int wt=curr.first;
            int node=curr.second;
            
            if(visited[node]) continue;
            visited[node]=1;
            sum+=wt;
            for(auto it:adj[node])
            {
                int adjNode=it.first;
                int adj_wt=it.second;
                if(!visited[adjNode])
                {
                    pq.push({adj_wt,adjNode});
                }
            }
        }
        return sum;
    }
    
};