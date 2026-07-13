class Solution {
public:
    int count_set_bit(int n)
    {
        int count=0;
        while(n>0)
        {
            count+=(1&n);
            n=n>>1;
        }
        return count;
    }
    int minBitFlips(int start, int goal) 
    {
        return count_set_bit(start^goal);
    }
};