class Solution {
public:

    void reverse(TreeNode* from, TreeNode* to)
    {
        if(from == to) return;

        TreeNode *x = from, *y = from->right, *z;

        while(true)
        {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
            if(x == to) break;
        }
    }

    void printReverse(TreeNode* from, TreeNode* to, vector<int>& ans)
    {
        reverse(from, to);

        TreeNode* p = to;

        while(true)
        {
            ans.push_back(p->val);
            if(p == from) break;
            p = p->right;
        }

        reverse(to, from);
    }

    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ans;

        TreeNode dummy(0);
        dummy.left = root;

        TreeNode* cur = &dummy;

        while(cur)
        {
            if(cur->left == NULL)
            {
                cur = cur->right;
            }
            else
            {
                TreeNode* pred = cur->left;

                while(pred->right && pred->right != cur)
                    pred = pred->right;

                if(pred->right == NULL)
                {
                    pred->right = cur;
                    cur = cur->left;
                }
                else
                {
                    printReverse(cur->left, pred, ans);
                    pred->right = NULL;
                    cur = cur->right;
                }
            }
        }

        return ans;
    }
};