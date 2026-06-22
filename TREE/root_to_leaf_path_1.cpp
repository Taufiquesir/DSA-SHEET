/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    void dfs(Node* root,vector<int>path,vector<vector<int>> &ans)
    {
        if(root==NULL) return;
        path.push_back(root->data);
        if(root->left==NULL && root->right==NULL)
        {
            ans.push_back(path);
        }
        dfs(root->left,path,ans);
        dfs(root->right,path,ans);
    }
    vector<vector<int>> Paths(Node* root) 
    {
        // code here
        vector<vector<int>>ans;
        vector<int>path;
        
        dfs(root,path,ans);
        return ans;
    }
};