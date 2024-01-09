#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (b); ++i)

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(i, 0, t)
    {
        int n;
        cin >> n;
        vector<ll> v;
        rep(j, 0, n)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        rep(j, 0, n)
        {
            int b;
            cin >> b;
            v[j] -= b;
        }
        ll f = *max_element(v.begin(), v.end());
        vector<ll> ans;
        rep(j, 0, n)
        {
            if (v[j] == f)
            {
                ans.push_back(j + 1);
            }
        }
        cout << ans.size() << '\n';
        for (ll node : ans)
        {
            cout << node << ' ';
        }
        cout << '\n';
    }
}