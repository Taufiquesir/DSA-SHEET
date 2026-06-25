class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> ans;

        while(root)
        {
            if(root->left == NULL)
            {
                ans.push_back(root->val);
                root = root->right;
            }
            else
            {
                TreeNode* curr = root->left;

                while(curr->right && curr->right != root)
                {
                    curr = curr->right;
                }

                if(curr->right == NULL)
                {
                    ans.push_back(root->val);   // Visit first time
                    curr->right = root;
                    root = root->left;
                }
                else
                {
                    curr->right = NULL;
                    root = root->right;
                }
            }
        }

        return ans;
    }
};