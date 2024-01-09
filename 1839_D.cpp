#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<vector<vector<vector<ll>>>> dp;

vector<ll> cols; // start, end

ll solve(ll i, ll j, ll k, ll l) // num of elements, max weight, num of divisions
{
    if (k < 0)
    {
        return -1;
    }
    if (i < 0)
    {
        if (l == 0 && k == 0)
            return -1;
        return 0;
    }
    // cout << i << j << k << l << endl;
    // cout << dp.size() << dp[0].size() << endl;
    if (dp[i][j][k][l] != -2)
    {
        return dp[i][j][k][l];
    }
    if (l == 0)
    {
        ll res = max(solve(i - 1, j, k - 1, 1), solve(i - 1, j, k, 0));
        dp[i][j][k][l] = res;
        return res;
    }
    if (l == 1)
    { // uneeded comment
        if (cols[i] > j)
        {
            dp[i][j][k][l] = -1;
            return -1;
        }
        ll res = max(solve(i - 1, cols[i] - 1, k, 0), solve(i - 1, cols[i] - 1, k, 1));
        if (res != -1)
        {
            res++;
        }
        dp[i][j][k][l] = res;
        return res;
    }
}

void output(ll n)
{
    dp.clear();
    dp.resize(n);
    for (ll i = 0; i < dp.size(); i++)
    {
        dp[i].resize(n + 1);
        for (ll j = 0; j < dp[i].size(); j++)
        {
            dp[i][j].resize(n + 1);
            for (ll k = 0; k < dp[i][j].size(); k++)
            {
                dp[i][j][k].resize(2, -2);
            }
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        cout << n - max(solve(n - 1, n, i, 0), solve(n - 1, n, i, 1)) << " ";
    }
    cout << endl;
}

int main()
{
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        cols.clear();
        for (ll j = 0; j < n; j++)
        {
            ll c;
            cin >> c;
            cols.push_back(c);
        }
        output(n);
    }
}
