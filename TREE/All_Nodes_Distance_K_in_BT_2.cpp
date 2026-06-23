class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>parent;
    void find_parent(TreeNode* root)
    {
        if(root==NULL) return;
        if(root->left)
        {
            parent[root->left]=root;
            find_parent(root->left);
        }
        if(root->right)
        {
            parent[root->right]=root;
            find_parent(root->right);
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        vector<int>result;
        find_parent(root);

        queue<TreeNode*>q;
        unordered_set<TreeNode*>visited;
        q.push(target);
        visited.insert(target);

        while(!q.empty() && k--)
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* node=q.front();
                q.pop();

                if(parent.count(node) && !visited.count(parent[node]))
                {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
                if(node->left && !visited.count(node->left))
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && !visited.count(node->right))
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }
            }
        }
        while(!q.empty())
        {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;        
    }
};