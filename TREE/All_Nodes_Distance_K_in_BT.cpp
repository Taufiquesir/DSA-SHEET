/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

class Solution 
{

  public:
  
    unordered_map<Node*,Node*>parent;
    void inorder(Node* root)
    {
        if(root==NULL) return;
        if(root->left)
        {
            parent[root->left]=root;
            inorder(root->left);
        }
        if(root->right)
        {
            parent[root->right]=root;
            inorder(root->right);
        }
    }
    
    Node* findTarget(Node* root, int target)
    {
        if(root==NULL) return NULL;
        if(root->data == target) return root;

        Node* left = findTarget(root->left, target);
        if(left) return left;

        return findTarget(root->right, target);
    }
    
    void BFS(Node* targetNode,int k,vector<int> &result)
    {
        queue<Node*>q;
        q.push(targetNode);
        unordered_set<Node*>visited;
        visited.insert(targetNode);
        
        while(!q.empty())
        {
            int size=q.size();
            if(k==0) break;
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
            k--;
        }
        while(!q.empty())
        {
            result.push_back(q.front()->data);
            q.pop();
        }
        sort(result.begin(), result.end());
    }

    vector<int> KDistanceNodes(Node* root, int target, int k) 
    {
        // return the sorted vector of all nodes at k dist
        vector<int>result;
        inorder(root);
        Node* targetNode = findTarget(root, target);
        BFS(targetNode,k,result);
        return result;
        
    }
};