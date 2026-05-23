class Solution {
  public:
    void reverse1(vector<int>& arr,int start,int end)
    {
        int left=start;
        int right=end;
        while(left<right)
        {
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
    void rotateArr(vector<int>& arr, int d) 
    {
        // code here
        int n=arr.size();
        d=d%n;
        reverse1(arr,0,n-1);
        reverse1(arr,0,d);
        reverse1(arr,d+1,n-1);
    }
};