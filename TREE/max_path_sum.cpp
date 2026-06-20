/*
Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int max_path_sum(Node* root,int &maxi)
    {
        if(root==NULL) return 0;
        int left=max(0,max_path_sum(root->left,maxi));
        int right=max(0,max_path_sum(root->right,maxi));
        maxi=max(maxi,left+right+root->data);
        return max(left,right)+root->data;
    }
    int findMaxSum(Node *root) 
    {
        // code here
        int maxi=INT_MIN;
        max_path_sum(root,maxi);
        return maxi;
        
        
    }
};