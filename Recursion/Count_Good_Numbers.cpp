class Solution {
public:
    const long long MOD = 1e9 + 7;
    long long find_power(long long x,long long n)
    {
        if(n==0) return 1;
        long long half=find_power(x,n/2)%MOD;
        if(n%2==0) return (half*half)%MOD;
        return (half*half*x)%MOD;
    }
    int countGoodNumbers(long long n)
    {
        long long even=(n+1)/2;
        long long odd=n/2;
        return (find_power(5,even)*find_power(4,odd))%MOD;
    }
};