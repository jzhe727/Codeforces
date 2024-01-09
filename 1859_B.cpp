#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < (b); ++i)
using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(i, 0, t)
    {
        // vector<pair<int, int>> t;
        const int MAX = 1'000'000'001;
        int globmin = MAX;
        int globmin2 = MAX;
        ll min2sum = 0;
        int n;
        cin >> n;
        rep(j, 0, n)
        {
            int m;
            cin >> m;
            vector<int> v;
            rep(k, 0, m)
            {
                int a;
                cin >> a;
                v.push_back(a);
            }
            sort(v.begin(), v.end());
            globmin = min(globmin, v[0]);
            globmin2 = min(globmin2, v[1]);
            min2sum += v[1];
        }
        cout << min2sum - globmin2 + globmin << '\n';
    }
}