class Solution {
  public:
    void Helper(Node* root,vector<int>&ans)
    {
        if(root==NULL) return;
        Helper(root->left,ans);
        ans.push_back(root->data);
        Helper(root->right,ans);
    }
    int kthSmallest(Node *root, int k) 
    {
        // code here
        vector<int>ans;
        Helper(root,ans);
        return ans.size()<k?-1:ans[k-1];
    }
};