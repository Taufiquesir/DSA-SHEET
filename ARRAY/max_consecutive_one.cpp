class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int n = nums.size();
        int max_count = 0;
        int count = 0;
        for (auto it : nums)
        {
            if (it == 1)
            {
                count++;
                max_count = max(max_count, count);
            }
            else
            {
                count = 0;
            }
        }
        return max_count;
    }
};