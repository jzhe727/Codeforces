#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
#define rep(i, a, b) for (int i = a; i < b; ++i)

const ll MOD = 1'000'000'007;
int n, m;
vector<vector<pll>> dp;

pll fracadd(pll f1, pll f2)
{
    ll denom = f1.second * f2.second;
    ll num = (f1.first * f2.second + f2.first * f1.second);
    num %= MOD;
    denom %= MOD;
    return {num, denom};
}

pll expected(ll i, ll j)
{
    // expected number of steps for i to catch up to j
    if (i == j)
    {
        return pll({0, 1});
    }
    if (j == m)
    {
        return pll({m - i, 1});
    }
    pll blank = {0, 0};
    if (dp[i][j] != blank)
    {
        return dp[i][j];
    }
    pll p1 = expected(i + 1, j);
    pll p2 = expected(i, j + 1);
    p1.second <<= 1;
    p1.second %= MOD;
    p2.second <<= 1;
    p2.second %= MOD;
    pll val = fracadd({1, 2}, fracadd(p1, p2));
    dp[i][j] = val;
    return val;
}

ll inv(ll a, ll b)
{
    return 1 < a ? b - inv(b % a, a) * b / a : 1;
}

int main()
{
    cin >> n >> m;
    m++;
    dp.resize(m);
    for (auto &v : dp)
    {
        v.resize(m);
    }
    vector<ll> nums;
    rep(i, 0, n)
    {
        ll x;
        cin >> x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    pll total = {0, 1};
    rep(i, 0, n - 1)
    {
        total = fracadd(total, expected(nums[i], nums[i + 1]));
    }
    total = fracadd(total, expected(nums[n - 1], m));
    // cout << total.first << ' ' << total.second << ' ' << inv(total.second, MOD) << endl;
    cout << (total.first * inv(total.second, MOD)) % MOD << endl;
}