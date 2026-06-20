class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) 
    {
        // code here
        vector<int>ans;
        if(root==NULL) return ans;
        bool left_to_right=true;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int>level(size);
            for(int i=0;i<size;i++)
            {
                Node*node=q.front();
                q.pop();
                int index=left_to_right?i:size-i-1;
                level[index]=node->data;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            left_to_right=!left_to_right;
            for(auto it:level)
            {
                ans.push_back(it);
            }
        }
        return ans;
    }
};