#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (b); ++i)

vector<unordered_map<int, int>> dp;
vector<int> nums;
int n, k;
int solve(int i, int v)
{
    // cout << i << endl;
    if (i == n)
    {
        return -1;
    }
    if (nums[i] >= v)
    {
        return 0;
    }
    if (dp[i][v] != 0)
    {
        return dp[i][v];
    }

    int val1 = solve(i + 1, v - 1);
    if (val1 == -1)
    {
        dp[i][v] = -1;
        return -1;
    }
    int total = val1 + (v - nums[i]);
    if (total <= k)
    {
        dp[i][v] = total;
        return total;
    }

    dp[i][v] = -1;
    return -1;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(i, 0, t)
    {
        cin >> n >> k;
        int m = 0;
        int largest = 0;
        nums.clear();
        dp.clear();
        dp.resize(n);
        rep(j, 0, n)
        {
            int a;
            cin >> a;
            largest = max(largest, a);
            nums.push_back(a);
        }
        rep(j, 0, n)
        {
            int lower = largest;
            int upper = largest + n + 1;
            int mid = (lower + upper) / 2;
            for (; lower < upper - 1; mid = (lower + upper) / 2)
            {
                if (solve(j, mid) == -1)
                {
                    upper = mid;
                }
                else
                {
                    lower = mid;
                }
            }
            m = (int)max(lower, m);
        }
        cout << m << '\n';
    }
}