class Solution {
public:
    void DFS(vector<vector<int>>& image, int i, int j, int New_color,int org_color)
    {
        if(i<0||j<0||i>=image.size()||j>=image[0].size()||image[i][j]!=org_color||image[i][j]==New_color) return;
        image[i][j]=New_color;
        DFS(image,i-1,j,New_color,org_color);  //up
        DFS(image,i+1,j,New_color,org_color);  //down
        DFS(image,i,j-1,New_color,org_color);  //Left
        DFS(image,i,j+1,New_color,org_color);  //Right

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int New_color=color;
        int org_color=image[sr][sc];
        DFS(image,sr,sc,New_color,org_color);
        return image;
        
    }
};