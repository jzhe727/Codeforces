#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (b); ++i)

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(j, 0, t)
    {
        int n;
        cin >> n;
        vector<ll> nums;
        rep(i, 0, n)
        {
            ll a;
            cin >> a;
            nums.push_back(a);
        }
        ll total = 0;
        for (int i = n - 1; i > 0; --i)
        {
            if (nums[i - 1] > nums[i])
            {
                total = max(total, nums[i - 1]);
            }
        }
        cout << total << '\n';
    }
}