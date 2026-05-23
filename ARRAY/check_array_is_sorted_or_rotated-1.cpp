class Solution {
public:
    bool check_rotated(vector<int> arr,int point,int n)
    {
        vector<int>rotated_array(n);
        
        for(int i=0;i<n;i++)
        {
            rotated_array[(i+point)%n]=arr[i];
        }
        return check_sorted(rotated_array);
    }
    bool check_sorted(vector<int> arr)
    {
        for(int i=1;i<arr.size();i++)
        {
            if(arr[i-1]>arr[i]) return false;
        }
        return true;
    }
    bool check(vector<int>& nums)
    {
        int n=nums.size();
        int point=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]>nums[i])
            {
               point=n-i;
               break;
            }
        }
        return  check_rotated(nums,point,n);        
    }
};