class Solution {
  public:
  
    int find(int x, vector<int> &parent)
    {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x], parent);
    }
    vector<int> DSU(int n, vector<vector<int>>& queries) 
    {
        // code here
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
        vector<int> ans;
        for (auto &q : queries)
        {
            if (q[0] == 1) 
            {
                int x = q[1];
                int z = q[2];

                int px = find(x,parent);
                int pz = find(z,parent);

                if (px != pz)
                    parent[px] = pz;      // Attach x's set to z's set
            }
            else 
            {
                ans.push_back(find(q[1],parent));
            }
        }
        return ans;
    }
};