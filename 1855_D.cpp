#pragma GCC optimize("O3")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (b); ++i)

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<bool> reachable(n, 0);
    vector<int> nums;
    nums.reserve(n);
    bitset<200'001> r;
    r[0] = 1;
    rep(i, 0, n)
    {
        int a;
        cin >> a;
        nums.push_back(a);
    }

    vector<ll> score(n);
    ll cscore = 1;
    int far = n;
    rep(i, 0, n)
    {
        cscore = cscore + nums[i] - 1;
        score[i] = cscore;
        if (cscore <= 0)
        {
            far = i;
            break;
        }
    }
    bitset<200'001> mask;
    r[0] = 1;

    rep(i, 0, far)
    {
        r |= ((r & (~mask)) << nums[i]);
        mask <<= 1;
        mask.set(0);
    }
    ll best = 0;
    // cout << r[2] << endl;
    // cout << score[2] << endl;
    rep(i, 0, n)
    {
        if (r[i])
        {
            best = max(best, score[i]);
        }
    }
    rep(i, n, 200'001)
    {
        if (r[i])
        {
            best = max(best, score[n - 1] - (i - n + 1));
        }
    }
    cout << best << endl;
}