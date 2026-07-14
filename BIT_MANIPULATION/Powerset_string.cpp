class Solution {
  public:
    vector<string> powerSet(string &s) 
    {
        // Code here
        int n=s.size();
        int num_of_subset=1<<n;
        vector<string>ans;
        for(int i=0;i<num_of_subset;i++)
        {
            string temp="";
            for(int j=0;j<n;j++)
            {
                if(i &(1<<j))
                {
                    temp+=s[j];
                }
            }
            ans.push_back(temp);            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};