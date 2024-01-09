#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)

typedef long long ll;

int al[4] = {-1, -1, 1, 1};
int bl[4] = {-1, 1, -1, 1};
vector<int> a;
vector<int> b;
vector<vector<vector<ll>>> dp;
void solve(int n, int k)
{
    // cout << dp[0][0].size() << endl;
    dp[0][0][4] = 0;
    rep(m, 0, 4)
    {
        dp[0][1][m] = al[m] * a[0] + bl[m] * b[0];
    }
    dp[0][1][4] = 0;
    rep(m, 0, 4)
    {
        dp[0][1][4] = max(dp[0][1][4], dp[0][1][m] - al[m] * b[0] - bl[m] * a[0]);
    }
    rep(i, 1, n)
    {
        dp[1][0][4] = 0;
        rep(j, 1, k + 1)
        {
            // first four are open interals, last one is closed
            rep(m, 0, 4)
            {
                dp[1][j][m] = max(dp[1 - 1][j - 1][m], dp[1 - 1][j - 1][4] + al[m] * a[i] + bl[m] * b[i]);
            }
            dp[1][j][4] = dp[1 - 1][j][4];
            rep(m, 0, 4)
            {
                dp[1][j][4] = max(dp[1][j][4], dp[1][j][m] - al[m] * b[i] - bl[m] * a[i]);
            }
        }
        dp[0] = dp[1];
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(i, 0, t)
    {
        int n, k;
        cin >> n >> k;
        a.clear();
        b.clear();
        rep(j, 0, n)
        {
            int aj;
            cin >> aj;
            a.push_back(aj);
        }
        rep(j, 0, n)
        {
            int bj;
            cin >> bj;
            b.push_back(bj);
        }
        dp.clear();
        dp.resize(2);
        for (auto &v : dp)
        {
            v.resize(k + 1);
            for (auto &g : v)
            {
                g.resize(5, 8000 * (ll)INT32_MIN);
            }
        }
        solve(n, k);
        // if (i == 1)
        // {
        //     cout << dp[1][1][4] << ' ';
        //     cout << dp[0][1][4] << ' ';
        // }
        cout << dp[0][k][4] << '\n';
    }
}