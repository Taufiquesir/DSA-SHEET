/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution
{
public:
    vector<vector<int>> treeTraversal(TreeNode *root)
    {
        // your code goes here
        vector<vector<int>> ans;
        vector<int> Pre, In, Post;
        if (root == NULL)
            return ans;
        stack<pair<TreeNode *, int>> st;
        st.push({root, 1});

        while (!st.empty())
        {
            auto it = st.top();
            st.pop();

            if (it.second == 1)
            {
                Pre.push_back(it.first->data);
                it.second++;
                st.push(it);
                if (it.first->left)
                    st.push({it.first->left, 1});
            }

            else if (it.second == 2)
            {
                In.push_back(it.first->data);
                it.second++;
                st.push(it);
                if (it.first->right)
                    st.push({it.first->right, 1});
            }
            else
            {
                Post.push_back(it.first->data);
            }
        }
        ans.push_back(In);
        ans.push_back(Pre);
        ans.push_back(Post);
        return ans;
    }
};