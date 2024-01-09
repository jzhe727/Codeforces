#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
typedef long long ll;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(test, 0, t)
    {
        int n;
        cin >> n;
        vector<ll> a;
        rep(i, 0, n)
        {
            ll ai;
            cin >> ai;
            a.push_back(ai);
        }
        ll total = 0;
        bool picked = false;
        ll best = INT32_MIN;
        rep(i, 0, n)
        {
            while (!picked && i < n)
            {
                // i is an odd card
                if (a[i] > 0)
                {
                    total = a[i];
                    picked = true;
                    i++;
                }
                else
                {
                    if (i + 1 < n && a[i] + a[i + 1] < 0)
                    {
                        total = 0;
                        picked = true;
                        i += 2;
                    }
                    else if (i + 1 >= n)
                    {
                        // best = 0;
                        break;
                    }
                    else
                    {
                        total = a[i] + a[i + 1];
                        i += 2;
                        picked = true;
                    }
                }
            }
            if (i < n && a[i] > 0)
            {
                total += a[i];
            }
        }
        // reverse(a.begin(), a.end());
        // ll best = 0;
        // ll total = 0;
        // ll evens = 0;
        // rep(i, 0, n)
        // {
        //     if ((n - i) & 1)
        //     {
        //         if (a[i] > 0)
        //             total += a[i];
        //     }
        //     else
        //     {
        //     }
        // }
        cout << total << '\n';
    }
}