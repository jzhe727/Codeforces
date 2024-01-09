
#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test)
    {
        int n;
        int k;
        vector<pair<int, int>> c; // cost, -index
        cin >> n;
        rep(i, 0, n)
        {
            int ci;
            cin >> ci;
            c.push_back({ci, -i});
        }
        cin >> k;
        sort(c.begin(), c.end());
        vector<pair<int, int>> breakpoints; // number, index
        int promotable = k;
        int discount = 0;
        int pos = -1;
        for (auto &ci : c)
        {
            if (pos < (-ci.second))
            {
                int purchase = min(k / (ci.first - discount), promotable);
                if (purchase != 0)
                {
                    breakpoints.push_back({purchase, -ci.second});
                    k -= purchase * (ci.first - discount);
                    promotable = purchase;
                    discount = ci.first;
                    pos = -ci.second;
                }
            }
        }
        pos = 0;
        for (auto &b : breakpoints)
        {
            while (pos <= b.second)
            {
                cout << b.first << ' ';
                ++pos;
            }
        }
        while (pos < n)
        {
            cout << 0 << ' ';
            ++pos;
        }
        cout << '\n';
    }
}
// 21 minutes