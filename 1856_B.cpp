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
        int n;
        cin >> n;
        unordered_map<ll, ll> nums;
        ll sum = 0;
        rep(j, 0, n)
        {
            ll a;
            cin >> a;
            nums[a]++;
            sum += a;
        }
        ll maxcount = nums[1];
        if (maxcount > (sum - n) || n == 1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
}