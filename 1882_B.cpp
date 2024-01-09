#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
typedef long long ll;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(test, 0, t)
    {
        int n;
        cin >> n;
        vector<ll> s;
        rep(i, 0, n)

        {
            ll si, k;
            si = 0;
            cin >> k;
            rep(j, 0, k)
            {
                int sh;
                cin >> sh;
                si |= ((ll)1 << sh);
            }
            s.push_back(si);
        }
        ll total = 0;
        // sort(s.begin(), s.end());
        rep(i, 0, n)
        {

            total |= s[i];
        }
        int best = 0;
        rep(sh, 1, 51)
        {

            if ((total >> sh) & 1)
            {
                ll start = 0;
                rep(i, 0, n)
                {
                    if (!((s[i] >> sh) & 1))
                    {
                        start |= s[i];
                    }
                }
                best = max(best, __builtin_popcountll(start));
            }
        }
        cout << best << '\n';
    }
}