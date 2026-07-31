class Solution {
public:
    void find_subset(int index,vector<int>& nums,int n,
            vector<int> &temp,vector<vector<int>> &ans)
    {
        if(index>=n)
        {
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        find_subset(index+1,nums,n,temp,ans);
        temp.pop_back();
        find_subset(index+1,nums,n,temp,ans);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>temp;
        find_subset(0,nums,n,temp,ans);
        return ans;        
    }
};