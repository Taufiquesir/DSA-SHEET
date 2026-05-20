#include <bits/stdc++.h>
using namespace std;
long long sum_of_all_divisors(long long n)
{
    long long sum_of_divisors = 0;
    for (long long i = 1; i <= n; i++)
    {
        if (n % i == 0)
            sum_of_divisors += i;
    }
    return sum_of_divisors;
}
long long sumOfDivisors(long long n)
{
    // Code here
    long long ans = 0;
    while (n)
    {
        ans += sum_of_all_divisors(n--);
    }
    return ans;
}

int main()
{
    long long number;
    cout << "Enter the number: ";
    cin >> number;
    long long result = sumOfDivisors(number);
    cout << result << endl;
    return result;
}