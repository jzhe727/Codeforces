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
        int n, k;
        cin >> n >> k;
        vector<int> v;
        vector<bool> found(n + 1);
        rep(j, 0, n)
        {
            int a;
            cin >> a;
            v.push_back(a);
            found[a] = true;
        }
        int missing;
        rep(j, 0, n + 1)
        {
            if (!found[j])
            {
                missing = j;
            }
        }
        v.push_back(missing);
        k %= n + 1;
        rep(j, n + 1 - k, n + 1)
        {
            cout << v[j] << ' ';
        }
        rep(j, 0, n - k)
        {
            cout << v[j] << ' ';
        }
        cout << '\n';
    }
}