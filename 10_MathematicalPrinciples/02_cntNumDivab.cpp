// Count of numbers from 1 to n that are divisible by a or b ,  1 < a,b < n
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int res = 0;
    // Find the number divisible by a
    res += (n / a);
    // Number divisible by b
    res += (n / b);
    // Subtract by number divisible by a and b
    res -= (n / (a * b));
    cout << res << endl;
    return 0;
}