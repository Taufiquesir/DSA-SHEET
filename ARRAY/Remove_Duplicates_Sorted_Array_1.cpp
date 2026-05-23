class Solution {
  public:
    vector<int> removeDuplicates(vector<int> &arr) 
    {
        // code here
        int n=arr.size();
        vector<int>ans;
        int curr=arr[0];
        ans.push_back(curr);
       
        for(int i=1;i<n;i++)
        {
           if(arr[i]!=curr)
           {
               curr=arr[i];
               ans.push_back(curr);
               
           }
        }
        return ans;
    }
};