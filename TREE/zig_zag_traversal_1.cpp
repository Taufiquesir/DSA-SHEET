/*
Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) 
    {
        // code here
        vector<int>ans;
        int level_counter=1;
        if(root==NULL) return ans;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>level;
            for(int i=0;i<size;i++)
            {
                Node*node=q.front();
                q.pop();
                level.push_back(node->data);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(level_counter%2==0) reverse(level.begin(),level.end());
            for(auto it:level)
            {
                ans.push_back(it);
            }
            level_counter++;
        }
        return ans;
    }
};