class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) 
    {
        // code here
        if(root==NULL||root==n1||root==n2) return root;
        Node* left=LCA(root->left,n1,n2);
        Node* right=LCA(root->right,n1,n2);
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;
    }
};