class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            long long rem1=target-nums[i];
            for(int j=i+1;j<n;j++)
            {
                long long rem2=rem1-nums[j];
                int start=j+1,end=n-1;
                while(start<end)
                {
                    if(nums[start]+nums[end]==rem2)
                    {
                        st.insert({nums[i],nums[j],nums[start],nums[end]});
                        start++,end--;
                    }
                    else if(nums[start]+nums[end]<rem2)
                    {
                        start++;
                    }
                    else
                    {
                        end--;
                    }
                }
            }            
        }
        vector<vector<int>>ans(st.begin(),st.end()); 
        return ans;       
    }
};