class Solution
{
public:
    void moveZeroes(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int j = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                j = i;
                break;
            }
        }
        if (j == -1)
            return;
        for (int k = j + 1; k < n; k++)
        {
            if (arr[k] != 0)
            {
                swap(arr[k], arr[j]);
                j++;
            }
        }
    }
};