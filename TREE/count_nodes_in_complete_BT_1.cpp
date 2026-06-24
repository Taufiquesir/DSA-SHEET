class Solution {
public:
    void counting(TreeNode* root,int &count) 
    {
        if(root==NULL) return;
        count++;
        counting(root->left,count);
        counting(root->right,count);        
    }
    int countNodes(TreeNode* root) 
    {
        int count=0;
        counting(root,count);
        return count;                
    }
};
