class Solution {
  public:
  int count=1;
    void printNos(int n) 
    {
        // Code here
        if(count>n) return;
        cout<<count++<<" ";
        printNos(n);
    }
};