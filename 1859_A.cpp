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
        vector<int> a;
        int n;
        cin >> n;
        int m = 0;
        rep(j, 0, n)
        {
            int ai;
            cin >> ai;
            a.push_back(ai);
            m = max(m, ai);
        }
        vector<int> b;
        vector<int> c;
        rep(j, 0, n)
        {
            if (a[j] == m)
            {
                c.push_back(m);
            }
            else
            {
                b.push_back(a[j]);
            }
        }
        if (b.size() == 0)
        {
            cout << -1 << '\n';
        }
        else
        {
            cout << b.size() << ' ' << c.size() << '\n';
            for (auto bi : b)
            {
                cout << bi << ' ';
            }
            cout << '\n';
            for (auto ci : c)
            {
                cout << ci << ' ';
            }
            cout << '\n';
        }
    }
}