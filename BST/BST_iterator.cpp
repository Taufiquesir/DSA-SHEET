class BSTIterator {
public:
    stack<TreeNode*>s;
    void storeleftNodes(TreeNode* root)
    {
        if(root==NULL) root;
        while(root)
        {
            s.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) 
    {
        storeleftNodes(root);        
    }
    int next() 
    {
        TreeNode* ans=s.top();
        s.pop();

        storeleftNodes(ans->right);
        return ans->val;    
    }
    bool hasNext() 
    {
        return s.size()>0;        
    }
};