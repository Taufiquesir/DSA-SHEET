class Solution
{
public:
    // Function to count the frequency of all elements from 1 to N in the array.
    vector<int> frequencyCount(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        int max_element = arr[0];
        for (auto it : arr)
        {
            max_element = max(max_element, it);
        }

        int hash[n + 1] = {0};

        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= n)
                hash[arr[i]]++;
        }

        vector<int> ans(n, 0);
        for (int i = 1; i <= n; i++)
        {
            ans[i - 1] = hash[i];
        }
        return ans;
    }
};
