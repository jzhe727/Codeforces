#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
typedef long long ll;
using namespace std;
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
        vector<int> l(n + 1, 0);
        vector<int> frogs(n + 1, 0);
        rep(j, 0, n)
        {
            int a;
            cin >> a;
            if (a <= n)
                ++frogs[a];
        }
        // cout << frogs[1] << endl;
        for (int a = 1; a <= n; a++)
        {
            // if (frogs[a] > 0)
            // {
            for (int h = 0; h <= n; h += a)
            {
                l[h] += frogs[a];
            }
            // }
        }

        l[0] = 0;
        // cout << l[1] << endl;
        cout << *max_element(l.begin(), l.end()) << '\n';
    }
}