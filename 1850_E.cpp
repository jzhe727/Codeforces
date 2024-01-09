#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(i, 0, t)
    {
        ll n;
        ll c;
        vector<ll> p;
        cin >> n >> c;
        rep(j, 0, n)
        {
            ll s;
            cin >> s;
            p.push_back(s);
        }
        ll lower = 0;
        ll upper = 1000000000; // exclusive upper
        ll sum = 0;
        for (const auto &s : p)
        {
            sum += s * s;
        }
        ll length = accumulate(p.begin(), p.end(), ll(0));
        upper = min(upper, (c - sum) / (ll(4) * length) + (ll)1);
        upper = min(upper, (ll)sqrt((c - sum) / 4 / n) + 10);
        // cout << upper << '\n';
        ll curr = (lower + upper) >> 1;
        ll total = 0;
        while (total != c)
        {
            curr = (lower + upper) >> 1;
            total = length * (ll)4 * curr + n * (ll)4 * curr * curr + sum;
            if (total > c)
                upper = curr;
            else
            {
                lower = curr;
            }
            // if (upper <= lower)
            // {
            //     cout << "what" << endl;
            //     break;
            // }
            // cout << curr << "testing" << endl;
        }
        cout << curr << '\n';
    }
}