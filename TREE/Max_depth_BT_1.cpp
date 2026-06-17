/* The Node structure is
class Node {
public:
    int data;
    Node* left;
    Node* right;

};
}; */

class Solution {
  public:
    /*You are required to complete this method*/
    int maxDepth(Node *root) 
    {
        // Your code here
        if(root==NULL) return 0;
        int level=0;
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            while(size)
            {
                Node* node=q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                size--;
            }
            if(!q.empty()) level++;
        }
        return level+1;
    }
};