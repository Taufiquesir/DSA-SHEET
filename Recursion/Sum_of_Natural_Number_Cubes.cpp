class Solution {
  public:
  int sum=0;
    int sumOfSeries(int n) 
    {
        // code here
        if(n==0) return 0;
        return (n*n*n) + sumOfSeries(n-1);
    }
};