#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)

// bitset<2500> pos;
int main()
{
    int t;
    cin >> t;
    rep(i, 0, t)
    {
        // pos.reset();
        // pos[0] = 1;
        int n;
        cin >> n;
        int sum = 0;
        rep(j, 0, n)
        {
            int a;
            cin >> a;
            // pos |= (pos << a);
            sum += a;
        }
        if (sum % 2)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}