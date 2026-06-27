class Solution {
  public:
    void inorder_traversal(Node *root,vector<int> &inorder)
    {
        if(root==NULL) return;
        inorder_traversal(root->left,inorder);
        inorder.push_back(root->data);
        inorder_traversal(root->right,inorder);
    }
    bool findTarget(Node *root, int target) 
    {
        vector<int>inorder;
        inorder_traversal(root,inorder);
        int start=0,end=inorder.size()-1;
        while(start<end)
        {
            if(inorder[start]+inorder[end]==target) return true;
            else if(inorder[start]+inorder[end]<target) start++;
            else end--;
        }
        return false;
    }
};