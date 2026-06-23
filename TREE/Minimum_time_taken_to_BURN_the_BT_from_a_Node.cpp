class Solution {
public:
    unordered_map<Node*,Node*>parent;
    void find_parent(Node* root)
    {
        if(root==NULL) return;
        if(root->left)
        {
            parent[root->left]=root;
            find_parent(root->left);
        }
        if(root->right)
        {
            parent[root->right]=root;
            find_parent(root->right);
        }
    }

    Node* find_origin(Node* root,int target)
    {
        if(root==NULL) return NULL;
        if(root->data==target) return root;
        Node* left=find_origin(root->left,target);
        if(left) return left;
        return find_origin(root->right,target);
    }

    int minTime(Node* root, int target) 
    {
        int time=0;
        find_parent(root);
        Node* startNode=find_origin(root,target);

        queue<Node*>q;
        unordered_set<Node*>visited;
        q.push(startNode);
        visited.insert(startNode);

        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                Node* node=q.front();
                q.pop();

                if(parent.count(node) && !visited.count(parent[node]))
                {
                    q.push(parent[node]);
                    visited.insert(parent[node]);
                }
                if(node->left && !visited.count(node->left))
                {
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && !visited.count(node->right))
                {
                    q.push(node->right);
                    visited.insert(node->right);
                }
            }
            time++;
        }
        return time-1;        
    }
};