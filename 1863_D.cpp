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
        vector<vector<char>> v;
        int n, m;
        cin >> n >> m;
        v.resize(n);
        rep(j, 0, n)
        {
            rep(k, 0, m)
            {
                char c;
                cin >> c;
                v[j].push_back(c);
            }
        }
        bool ff = false;
        bool alt = false;
        rep(j, 0, n - 1)
        {
            rep(k, 0, m)
            {
                if (v[j][k] == 'U')
                {
                    v[j][k] = (alt) ? 'B' : 'W';
                    v[j + 1][k] = (alt) ? 'W' : 'B';
                    alt = !alt;
                }
            }
            if (alt)
            {
                ff = true;
            }
        }
        rep(k, 0, m - 1)
        {
            rep(j, 0, n)
            {
                if (v[j][k] == 'L')
                {
                    v[j][k] = (alt) ? 'B' : 'W';
                    v[j][k + 1] = (alt) ? 'W' : 'B';
                    alt = !alt;
                }
            }
            if (alt)
            {
                ff = true;
            }
        }
        if (ff)
        {
            cout << -1 << '\n';
        }
        else
        {
            rep(j, 0, n)
            {
                rep(k, 0, m)
                {
                    cout << v[j][k];
                }
                cout << '\n';
            }
        }
    }
}