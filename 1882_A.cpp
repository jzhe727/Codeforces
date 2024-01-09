#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(test, 0, t)
    {
        int n;
        cin >> n;
        vector<int> a;
        rep(i, 0, n)
        {
            int ai;
            cin >> ai;
            a.push_back(ai);
        }
        int b = 0;
        rep(i, 0, n)
        {
            b++;
            if (b == a[i])
                b++;
        }
        cout << b << '\n';
    }
}
