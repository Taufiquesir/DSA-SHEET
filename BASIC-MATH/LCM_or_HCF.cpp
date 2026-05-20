#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a = a % b;
        else
            b = b % a;
    }
    return a == 0 ? b : a;
}
vector<int> lcmAndGcd(int a, int b)
{
    int HCF = gcd(a, b);
    vector<int> LCM_and_HCF(2);
    int LCM = (a * b) / HCF;
    LCM_and_HCF[0] = LCM;
    LCM_and_HCF[1] = HCF;
    return LCM_and_HCF;
}
int main()
{
    int number1, number2;
    cout << "Enter the numbers:\n ";
    cin >> number1 >> number2;
    vector result = lcmAndGcd(number1, number2);
    cout << result[0] << result[1] << endl;
    return 0;
}