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
        int n;
        cin >> n;
        vector<pair<int, int>> segs;
        rep(j, 0, n)
        {
            int l, r, a, b;
            cin >> l >> r >> a >> b;
            segs.push_back({l, b});
        }
        sort(segs.begin(), segs.end());
        map<int, int> secs;
        pair<int, int> comb = segs[0];
        for (auto seg : segs)
        {
            if (seg.first <= comb.second)
            {
                comb.second = max(seg.second, comb.second);
            }
            else
            {
                secs[comb.first] = comb.second;
                comb = seg;
            }
        }
        secs[comb.first] = comb.second;
        int q;
        cin >> q;
        rep(h, 0, q)
        {
            int qi;
            cin >> qi;
            if (secs.upper_bound(qi) == secs.begin())
            {
                cout << qi << ' ';
            }
            else
            {
                int tp = (*(--secs.upper_bound(qi))).second;
                cout << max(tp, qi) << ' ';
            }
        }
        cout << '\n';
    }
}