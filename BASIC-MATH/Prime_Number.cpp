#include <bits/stdc++.h>
using namespace std;
int isPrime(int n)
{
    // code here
    vector<int> divisors;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            divisors.push_back(i);
    }
    sort(divisors.begin(), divisors.end());
    for (int i = 0; i < divisors.size(); i++)
    {
        cout << divisors[i] << " ";
    }
    return divisors.size();
}

int main()
{
    int number;
    cout << "Enter the number: ";
    cin >> number;
    if (number == 1)
        return 0;
    int result = isPrime(number);
    cout << result << endl;
    return result;
}