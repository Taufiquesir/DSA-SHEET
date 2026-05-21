class Solution {
  public:
    void solve(int left,int right,string& S)
    {
        if(left>=right) return;
        swap(S[left],S[right]);
        solve(left+1,right-1,S);
        
    }
    string reverse(string& S) 
    {
        // code here
        solve(0,S.size()-1,S);
        return S;
    }
};