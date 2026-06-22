class Solution {
  public:
    bool find_ancestors(Node* root,vector<int> &ans,int target)
    {
        if(root==NULL) return false;
        
        if(root->data==target) return true;
        
        if(find_ancestors(root->left,ans,target)||find_ancestors(root->right,ans,target))
        {
            ans.push_back(root->data);
            return true;
        }
        return false;
    }
    vector<int> ancestors(Node *root, int target) 
    {
        // Code here
        vector<int>ans;
        if(root==NULL) return ans;
        find_ancestors(root,ans,target);
        return ans;
    }
};