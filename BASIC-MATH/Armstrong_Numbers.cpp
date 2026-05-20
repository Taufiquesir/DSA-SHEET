#include <bits/stdc++.h>
using namespace std;

bool armstrongNumber(int n)
{
    int original_number = n;
    int sum = 0;
    while (n)
    {
        int rem = n % 10;
        sum += rem * rem * rem;
        n /= 10;
    }
    return sum == original_number;
}
int main()
{
    int number;
    cout << "Enter the number: ";
    cin >> number;
    bool result = armstrongNumber(number);
    cout << result << endl;
    return 0;
}