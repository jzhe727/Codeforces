#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int j = 0; j < t; ++j)
    {
        int n, k, x;
        cin >> n >> k >> x;
        if (k > (x + 1) || k > n)
        {
            cout << "-1" << '\n';
        }
        else
        {
            int sum = 0;
            int i = 0;
            for (; i < k; ++i)
            {
                sum += i;
            }
            sum += (n - i) * ((x == k) ? (x - 1) : x);
            cout << sum << '\n';
        }
    }
}