struct info
{
    int min;
    int max;
    int sz;

    info(int mn, int mx, int s)
    {
        min = mn;
        max = mx;
        sz = s;
    }
};

class Solution
{
public:
    info Helper(Node *root)
    {
        if (root == NULL)
        {
            return info(INT_MAX, INT_MIN, 0);
        }

        info left = Helper(root->left);
        info right = Helper(root->right);

        if (root->data > left.max && root->data < right.min)
        {
            return info(
                min(root->data, left.min),
                max(root->data, right.max),
                left.sz + right.sz + 1);
        }
        return info(
            INT_MIN,
            INT_MAX,
            max(left.sz, right.sz));
    }
    int largestBst(Node *root)
    {
        return Helper(root).sz;
    }
};

// find the largest BST in a binary tree
