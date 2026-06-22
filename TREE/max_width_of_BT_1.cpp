class Solution {
  public:
    int maxWidth(Node* root) 
    {
        // code here
        int max_width=0;
        if(root==NULL) return max_width;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            max_width=max(max_width,size);
            while(size--)
            {
                Node* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
        return max_width;
    }
};