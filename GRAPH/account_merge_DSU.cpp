class DSU {
    public:
    vector<int> parent,rank;

    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n,0);

        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }

    int findUpar(int x)
    {
        if(parent[x]==x) return x;
        return parent[x]=findUpar(parent[x]);
    }

    void unite(int x,int y)
    {
        x=findUpar(x);
        y=findUpar(y);

        if(x==y) return;
        if(rank[x]<rank[y]) parent[x]=y;
        else if (rank[x]>rank[y]) parent[y]=x;
        else
        {
            parent[y]=x;
            rank[x]++;
        }
    }
};
class Solution {
  public:
    vector<vector<string>> accMerge(vector<vector<string>>& arr) 
    {
        // code here
        int n=arr.size();
        DSU dsu(n);
        unordered_map<string,int> mapMailNode;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<arr[i].size();j++)
            {
                string mail=arr[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end())
                {
                    mapMailNode[mail]=i;
                }
                else
                {
                    dsu.unite(i,mapMailNode[mail]);
                }
            }
        }
        vector<string>mergedMail[n];
        for(auto it:mapMailNode)
        {
            string mail=it.first;
            int node=dsu.findUpar(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        
        for(int i=0;i<n;i++)
        {
            if(mergedMail[i].empty()) continue;
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string>temp;
            temp.push_back(arr[i][0]); //account name
            for(auto it:mergedMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
