class DSU
{
private:
    vector<int> parent, size;

public:
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUpar(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = findUpar(parent[x]);
    }

    void unite(int x, int y)
    {
        x = findUpar(x);
        y = findUpar(y);

        if (x == y)
            return;

        if (size[x] < size[y])
        {
            parent[x] = y;
            size[y] += size[x];
        }
        else
        {
            parent[y] = x;
            size[x] += size[y];
        }
    }

    int getSize(int node)
    {
        return size[findUpar(node)];
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) 
    {
        int n=stones.size();
        int maxrow=0;
        int maxcol=0;
        for(auto it:stones)
        {
            maxrow=max(maxrow,it[0]);
            maxcol=max(maxcol,it[1]);
        }
        DSU dsu(maxrow+maxcol+2);
        unordered_map<int,int> stoneNodes;
        for(auto it:stones)
        {
            int nodeRow=it[0];
            int nodeCol=it[1]+maxrow+1;
            dsu.unite(nodeRow,nodeCol);
            stoneNodes[nodeRow]=1;
            stoneNodes[nodeCol]=1;
        }
        int cnt=0;
        for(auto it:stoneNodes)
        {
            if(dsu.findUpar(it.first)==it.first)
            {
                cnt++;
            }
        }
        return n-cnt;
    }
};