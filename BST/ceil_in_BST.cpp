class Solution {
  public:
    int findCeil(Node* root, int x) 
    {
        // code here
        int ceil=-1;
        while(root)
        {
            if(root->data==x)
            {
                ceil=root->data;
                return ceil;
            }
            if(root->data<x)
            {
                root=root->right;
            }
            else
            {
                ceil=root->data;
                root=root->left;
            }
        }
        return ceil;
        
    }
};
