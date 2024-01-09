#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); ++i)
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(i, 0, t)
    {
        ll n;

        cin >> n;
        ll best = 0;
        rep(k, 2, n + 1)
        {
            ll total = 0;
            for (ll j = 0; j <= n - k; ++j)
            {
                total += (j * j);
            }
            for (ll p = 0; p < k; ++p)
            {
                total += ((n - (k - 1) + p) * (n - p));
            }
            total -= (n - (k - 1) / 2) * (n - k / 2);
            best = max(best, total);
        }
        cout << best << '\n';
    }
}