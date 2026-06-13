class Solution
{
public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr)
    {
        // code here
        int n = arr.size();
        for (int i = 0; i < n - 1; i++)
        {
            int mini = INT_MAX;
            int mini_index = i + 1;
            for (int j = i; j < n; j++)
            {
                if (arr[j] < mini)
                {
                    mini = arr[j];
                    mini_index = j;
                }
            }
            swap(arr[i], arr[mini_index]);
        }
    }
};