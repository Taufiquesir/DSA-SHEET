class Solution {
public:
    double find_square(double x, int power)
    {
        if(power==0) return 1;
        double half=find_square(x,power/2);
        if(power & 1) return half*half*x;
        return half*half;
    }
    double myPow(double x, int n) 
    {
        long long power=n;
       if(power<0) return 1/find_square(x,-power);
       return find_square(x,power);        
    }
};