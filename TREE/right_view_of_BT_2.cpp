class Solution {
  public:
    vector<int> ans;
    
    void dfs(Node* root, int depth) 
    {
        if (!root) return;
        
        if (depth == ans.size()) {
            ans.push_back(root->data);
        }
        
        dfs(root->right, depth + 1);
        dfs(root->left, depth + 1);
    }
    
    vector<int> rightView(Node* root) 
    {
        dfs(root, 0);
        return ans;
    }
};