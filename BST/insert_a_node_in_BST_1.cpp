class Solution {
  public:
    
    Node* insert(Node* root, int key) 
    {
        // code  here
        
        if(root==NULL) return new Node(key);
        if(root->data>key)
        {
            root->left=insert(root->left,key);
        }
        else
        {
            root->right=insert(root->right,key);
        }
        
        return root;
    }
};