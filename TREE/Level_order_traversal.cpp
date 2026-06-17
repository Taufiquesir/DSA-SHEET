/* A binary tree Node

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
 */
class Solution {
  public:
    vector<vector<int>> levelOrder(Node* root) 
    {
        vector<vector<int>>ans;
        if(root==NULL) return ans;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++)
            {
                Node* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                level.push_back(node->data);
            }
            ans.push_back(level);
        }
        return ans;
    }
};