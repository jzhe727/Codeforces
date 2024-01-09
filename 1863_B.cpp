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
        vector<int> v(n);
        rep(j, 0, n)
        {
            int a;
            cin >> a;
            v[a - 1] = j;
        }
        int s = 0;
        int c = v[0];
        rep(j, 1, n)
        {
            int next = v[j];
            if (next < c)
            {
                ++s;
            }
            c = next;
        }
        cout << s << '\n';
    }
}
