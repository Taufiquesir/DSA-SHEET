class BSTIterator 
{
    private:
    stack<Node*> st;
    bool reverse;
    
    public:
    BSTIterator(Node* root, bool isReverse) 
    {
        reverse = isReverse;
        pushAll(root);
    }

    void pushAll(Node* root) 
    {
        while(root)
        {
            st.push(root);
            if(reverse) root = root->right;
            else root = root->left;
        }
    }

    int next()
    {
        Node* temp = st.top();
        st.pop();

        if(reverse) pushAll(temp->left);
        else pushAll(temp->right);
        return temp->data;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

class Solution 
{
  public:
    bool findTarget(Node *root, int k) 
    {
        if(root == NULL) return false;

        BSTIterator left(root, false);   // Smallest
        BSTIterator right(root, true);   // Largest

        int i = left.next();
        int j = right.next();

        while(i < j)
        {
            if(i + j == k) return true;
            if(i + j < k) i = left.next();
            else j = right.next();
        }
        return false;
    }
};