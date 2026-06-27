class Solution {
  public:
    int inOrderSuccessor(Node *root, Node *k) 
    {
        // code here
        Node* successor=NULL;
        while(root!=NULL)
        {
            if(root->data<=k->data)
            {
                root=root->right;
            }
            else
            {
                successor=root;
                root=root->left;
            }
        }
        return successor ? successor->data : -1;
    }
};