#include <iostream>
using namespace std;
const int MOD = 1e9+7;
int main()
{
    // code
    int t;
    cin >> t;
    // precompute the sum of Prime square
    int n = 1e5 + 5;
    long long int *sieve = new long long int[n];
    sieve[1] = sieve[0] = 0;
    // Mark all the number as prime from 2
    for (int i = 2; i <= n; i++)
        sieve[i] = 1;
    // Fill the sieve
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i])
        {
            // mark all the non prime as true
            for (int j = i * 2; j <= n; j += i)
            {
                sieve[j] = 0;
            }
        }
    }
    // Now precompute the sum square
    for (int i = 2; i <= n; i++)
    {
        long long int currSum = sieve[i - 1];
        if (sieve[i])
        {
            // include the current value
            currSum = (currSum + (i*i))%MOD;
        }
        sieve[i] = currSum;
    }
    while (t--)
    {
        int l, r;
        cin >> l >> r;
        // want to find the sum of squares of nonPrime Numbers in the range l to r .
        // If i get the sum of Prime numbers from the range l to r
        // than i will be subtracting this
        l = l-1;
        long long int totSum = ((r * (r + 1) * ((2 * r) + 1)) / 6) - ((l * (l + 1) * ((2 * l) + 1)) / 6);
        long long int primeSumSq = sieve[r] - sieve[l];
        // cout<<totSum<<" "<<primeSumSq<<endl;
        cout << (totSum-primeSumSq)%MOD << endl;
    }
    return 0;
}