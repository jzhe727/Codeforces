#include <bits/stdc++.h>
// #pragma GCC optimize("O3")
// #pragma GCC target("avx2")
typedef int ll;
using namespace std;

// vector<vector<vector<ll>>> dp_prev;
// vector<vector<vector<ll>>> dp_cur;

int dp_1_arr[501][501][2];
int dp_2_arr[501][501][2];

auto dp_prev = dp_1_arr;
auto dp_cur = dp_2_arr;

vector<ll> cols; // start, end

ll solve(ll i, ll j, ll k, ll l) // num of elements, max weight, num of divisions
{
    // if (k < 0)
    // {
    //     return -1;
    // }

    // if (i < 0)
    // {
    //     if (l == 0 && k == 0)
    //         return -1;
    //     return 0;
    // }

    // cout << i << j << k << l << endl;
    // cout << dp.size() << dp[0].size() << endl;
    // if (dp_cur[j][k][l] != -2)
    // {
    //     return dp_cur[j][k][l];
    // }
    if (l == 0)
    {
        ll res = max(k - 1 < 0 ? -1 : dp_prev[j][k - 1][1], dp_prev[j][k][0]);
        dp_cur[j][k][l] = res;
        return res;
    }
    if (l == 1)
    { // uneeded comment
        if (cols[i] > j)
        {
            dp_cur[j][k][l] = -1;
            return -1;
        }
        ll res = max(dp_prev[cols[i] - 1][k][0], dp_prev[cols[i] - 1][k][1]);
        if (res != -1)
        {
            res++;
        }
        dp_cur[j][k][l] = res;
        return res;
    }
}

void output(ll n)
{
    // set up base case
    // dp_cur.resize(n + 1);
    // dp_prev.resize(n + 1);
    for (ll j = 0; j < n + 1; j++)
    {
        // dp_cur[j].resize(n + 1);
        // dp_prev[j].resize(n + 1);
        for (ll k = 0; k < n + 1; k++)
        {
            // dp_cur[j][k].resize(2);
            // dp_prev[j][k].resize(2);
            for (ll l = 0; l < 2; l++)
            {
                if (l == 0 && k == 0)
                {
                    dp_cur[j][k][l] = -1;
                }
                else
                {
                    dp_cur[j][k][l] = 0;
                }
            }
        }
    }

    for (ll i = 0; i < n; i++)
    {
        auto temp = dp_prev;
        dp_prev = dp_cur;
        dp_cur = temp;
        // swap(dp_prev, dp_cur);
        // dp_cur.clear();
        // dp_cur.resize(n + 1);
        // for (ll j = 0; j < dp_cur.size(); j++)
        // {
        //     dp_cur[j].resize(n + 1);
        //     for (ll k = 0; k < dp_cur[j].size(); k++)
        //     {
        //         dp_cur[j][k].resize(2, -2);
        //     }
        // }
        for (ll j = 0; j < n + 1; j++)
        {
            for (ll k = 0; k < n + 1; k++)
            {
                solve(i, j, k, 0);
                solve(i, j, k, 1);
            }
        }
    }
    for (ll k = 1; k <= n; k++)
    {
        cout << n - max(dp_cur[n][k][0], dp_cur[n][k][1]) << " ";
    }
    cout << "\n";
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
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
