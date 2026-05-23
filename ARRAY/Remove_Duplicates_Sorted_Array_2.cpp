class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) 
    {
        // code here
        vector<int>ans;
        map<int,int>mpp;
        for(auto it:arr)
        {
            if(!mpp[it])
            {
                ans.push_back(it);
                mpp[it]++;
            }
        }
        return ans;
    }
};