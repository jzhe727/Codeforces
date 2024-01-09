#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test)
    {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i)
        {
            int ai;
            cin >> ai;
            a.push_back(ai);
        }
        vector<array<int, 3>> subs;
        for (int l = 0; l < n; ++l)
        {
            vector<bool> has(n + 1);
            int cmex = 0;
            for (int r = l; r < n; ++r)
            {
                if (a[r] == a[l] && r != l)
                    break;
                bool minimal = false;
                has[a[r]] = true;
                while (has[cmex])
                {
                    ++cmex;
                    if (cmex > a[l])
                    {
                        minimal = true;
                    }
                }
                if (minimal)
                {
                    subs.push_back({l, r, cmex});
                }
            }
        }
        sort(subs.begin(), subs.end());
        vector<int> reached(8192, 5001);
        reached[0] = 0;
        for (auto &sub : subs)
        {
            for (int i = 0; i < reached.size(); ++i)
            {
                if (reached[i] <= sub[0])
                {
                    reached[i ^ sub[2]] = min(reached[i ^ sub[2]], sub[1] + 1);
                }
            }
        }
        int ans;
        for (int i = 0; i < reached.size(); ++i)
        {
            if (reached[i] < 5001)
            {
                ans = i;
            }
        }
        cout << ans << "\n";
    }
}