#include <bits/stdc++.h>
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
        int s = (n * (n - 1)) / 2;
        unordered_map<int, int> bc;
        rep(j, 0, s)
        {
            int b;
            cin >> b;
            bc[b]++;
        }
        vector<pair<int, int>> or_bc;
        for (auto p : bc)
        {
            or_bc.push_back(p);
        }
        sort(or_bc.begin(), or_bc.end());
        int count = n;
        vector<int> res;
        for (auto &p : or_bc)
        {
            while (p.second > 0)
            {
                p.second -= (--count);
                res.push_back(p.first);
            }
        }
        for (auto a : res)
        {
            cout << a << ' ';
        }
        cout << 1'000'000'000 << '\n';
    }
}