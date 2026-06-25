class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>ans;
        while(root!=NULL)
        {
            if(root->left==NULL) //Left part does not exist
            {
                ans.push_back(root->val);
                root=root->right;
            }
            else //Left part exist
            {
                TreeNode* curr=root->left;
                while(curr->right && curr->right!=root)
                {
                    curr=curr->right;
                }
                // if Left subtree is not traversed
                if(curr->right==NULL)
                {
                    curr->right=root;
                    root=root->left;
                }
                // If Left subtree is traversed
                else
                {
                    curr->right=NULL;
                    ans.push_back(root->val);
                    root=root->right;
                }
            }
        }
        return ans;        
    }
};