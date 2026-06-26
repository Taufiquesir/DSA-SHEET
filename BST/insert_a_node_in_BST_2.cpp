class Solution {
  public:
    
    Node* insert(Node* root, int key) 
    {
        // code  here
        if(root==NULL) return new Node(key);
        Node* curr=root;
        
        while(true)
        {
            if(curr->data>key)
            {
                if(curr->left==NULL)
                {
                    curr->left=new Node(key);
                    break;
                }
                curr=curr->left;
            }
            else
            {
                if(curr->right==NULL)
                {
                    curr->right=new Node(key);
                    break;
                }
                curr=curr->right;
            }
        }
        return root;
    }
};