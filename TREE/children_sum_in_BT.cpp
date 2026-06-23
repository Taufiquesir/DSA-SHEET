class Solution {
  public:
     bool isSumProperty(Node *root) 
    {
        // code here
        if(root==NULL) return true;
        if(root->left==NULL && root->right==NULL) return true;
        int left_sum=0,right_sum=0;
        if(root->left!=NULL) left_sum=root->left->data;
        if(root->right!=NULL) right_sum=root->right->data;
        if(root->data==(left_sum+right_sum) && isSumProperty(root->left) && isSumProperty(root->right))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
