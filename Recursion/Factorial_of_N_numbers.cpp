class Solution
{
public:
    int Factorial(int n)
    {
        // code here
        if (n == 1)
            return 1;
        return n + Factorial(n - 1);
    }
};