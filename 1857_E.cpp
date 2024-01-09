#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i = a; i < (b); ++i)

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(i, 0, t)
    {
        int n;
        cin >> n;
        vector<pair<ll, ll>> v;
        vector<ll> ans(n);
        rep(j, 0, n)
        {
            ll x;
            cin >> x;
            v.push_back({x, j});
        }
        sort(v.begin(), v.end());
        vector<ll> prefix;
        vector<ll> suffix;
        ll psum = 0;
        prefix.push_back(psum);
        rep(j, 1, n)
        {
            psum += (v[j].first - v[j - 1].first) * j; // exclude jth point
            prefix.push_back(psum);
        }
        ll ssum = 0;
        suffix.resize(n);
        suffix[n - 1] = 0;
        for (ll j = n - 1; j > 0; --j)
        {
            ssum += (v[j].first - v[j - 1].first) * (n - j); // exclude jth point
            suffix[j - 1] = ssum;
        }
        ll p1 = 0;
        ll p2 = 0;
        for (; p2 < n;)
        {
            while ((p1 + 1) < n && v[p1 + 1].first == v[p2].first)
            {
                ++p1;
            }
            ll num = p1 - p2 + 1;
            ll res = prefix[p2] + suffix[p1] + (n);
            while (p2 <= p1)
            {
                ans[v[p2].second] = res;
                ++p2;
            }
        }
        // for (auto num : prefix)
        // {
        //     cout << num << ' ';
        // }
        // cout << '\n';
        // for (auto num : suffix)
        // {
        //     cout << num << ' ';
        // }
        // cout << '\n';
        for (auto res : ans)
        {
            cout << res << ' ';
        }
        cout << '\n';
    }
}