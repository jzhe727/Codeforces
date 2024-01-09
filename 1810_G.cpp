#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("tree-vectorize")
using namespace std;
typedef long long ll;

const ll M = 1'000'000'000 + 7;

pair<ll, ll> inv1(ll a, ll b)
{
    // assert(a > b);
    // assert(b != 0);
    if (a == 1)
    {
        return {1, 0};
    }
    else
    {
        auto res = inv1(b, a % b);
        return {res.second, (res.first - (a / b) * res.second) % M};
    }
}

ll modinv(ll a)
{
    auto res = inv1(M, a);
    return (res.second % M + M) % M;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test)
    {
        int n;
        cin >> n;
        vector<ll> r(n);
        for (int i = 0; i < n; ++i)
        {
            ll x;
            ll y;
            cin >> x >> y;
            r[i] = (x * modinv(y)) % M;
        }
        array<ll, 5001> prev;
        array<ll, 5001> next;
        prev.fill(0);
        next.fill(0);
        for (int i = 0; i <= n; i++)
        {
            cin >> prev[i];
        }
        for (int i = 0; i < n; i++)
        {
            next[0] = ((M + 1 - r[i]) * prev[0] % M + r[i] * prev[1] % M) % M;
            for (int j = 1; j < (n - i); j++)
            {
                next[j] = (prev[j + 1] * r[i] % M + prev[j - 1] * (M + 1 - r[i]) % M) % M;
            }
            cout << next[0] << " ";
            swap(prev, next);
        }
        // ll res = 0;
        // for (ll j = 0; j <= n; j++)
        // {
        //     res = (res + j * prev[j]) % M;
        // }
        cout << "\n";
    }
    // cout << ((ll)9 * (ll)1 * modinv(6)) % M << ' ' << modinv(6) << endl;
}
