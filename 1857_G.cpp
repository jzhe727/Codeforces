#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

ll power(ll a, ll b, ll m)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

ll par(ll i, vector<pair<ll, ll>> &m)
{
    if (m[i].first == i)
    {
        return i;
    }
    m[i].first = par(m[i].first, m);
    return m[i].first;
}

ll join(ll a, ll b, vector<pair<ll, ll>> &m)
{
    a = par(a, m);
    b = par(b, m);
    m[b].first = a;
    m[a].second += m[b].second;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(i, 0, t)
    {
        int n, S;
        cin >> n >> S;
        vector<pair<ll, ll>> mw(n);
        rep(j, 0, n)
        {
            mw[j] = {j, 1};
        }
        vector<array<ll, 3>> es;
        ll res = 1;
        ll MOD = 998244353;
        rep(j, 0, n - 1)
        {
            int a, b, w;
            cin >> a >> b >> w;
            es.push_back({w, a - 1, b - 1});
        }
        sort(es.begin(), es.end());
        for (auto e : es)
        {
            ll a = par(e[1], mw);
            ll b = par(e[2], mw);
            ll multi = (mw[a].second) * (mw[b].second) - 1;
            res *= power(S - e[0] + 1, multi, MOD);
            res %= MOD;
            join(a, b, mw);
        }
        cout << res << '\n';
    }
}