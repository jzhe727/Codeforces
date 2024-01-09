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
        vector<ll> v;
        int n;
        ll k;
        cin >> n >> k;
        rep(j, 0, n)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        int maxl = 0;
        int l = 1;
        rep(j, 1, n)
        {
            if (v[j] - v[(j - 1)] > k)
            {
                maxl = max(maxl, l);
                l = 1;
            }
            else
            {
                ++l;
            }
        }
        maxl = max(maxl, l);
        cout << (n - maxl) << '\n';
    }
}