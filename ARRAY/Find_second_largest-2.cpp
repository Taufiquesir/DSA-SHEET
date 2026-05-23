class Solution {
  public:
    int getSecondLargest(vector<int> &arr) 
    {
        // code here
        int n=arr.size();
        int largest=arr[0];
        int Second_largest=-1;
        for(auto it:arr)
        {
            largest=max(largest,it);
           
        } 
        for(auto it:arr)
        {
            if(it!=largest && it>Second_largest)
            {
                Second_largest=it;
            }
        }
        return Second_largest;
    }
};