#include <bits/stdc++.h>
using namespace std;
typedef unsigned int uint;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test)
    {
        int n, m;
        cin >> n >> m;
        uint x = 0;
        uint a;
        for (int i = 0; i < n; ++i)
        {
            cin >> a;
            x ^= a;
        }
        uint y = 0;
        uint b;
        for (int i = 0; i < m; ++i)
        {
            cin >> b;
            y |= b;
        }
        if (n & 1)
        {
            cout << x << ' ' << (x | y) << '\n';
        }
        else
        {
            cout << (x & (~y)) << ' ' << x << '\n';
        }
    }
}