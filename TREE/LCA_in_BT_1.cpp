class Solution {
  public:
    bool find_path(Node* root,vector<Node*> &path,int target)
    {
        if(root==NULL) return false;
        path.push_back(root);
        if(root->data==target) return true;
        if(find_path(root->left,path,target)||find_path(root->right,path,target))
        {
            return true;
        }
        path.pop_back();
        return false;
    }
    Node* lca(Node* root, int n1, int n2) 
    {
        vector<Node*>p1,p2;
        find_path(root,p1,n1);
        find_path(root,p2,n2);
        int n=min(p1.size(),p2.size());
        Node* ancestor=nullptr;
        for(int i=0;i<n;i++)
        {
            if(p1[i]!=p2[i]) break;
            ancestor=p1[i];
        }
        return ancestor;
    }
};