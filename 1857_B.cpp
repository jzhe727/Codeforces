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
        string n;
        cin >> n;
        int trunc = n.size();
        for (int j = n.size() - 1; j > 0; --j)
        {
            if (n[j] >= '5')
            {
                if (n[j - 1] != '9')
                {
                    n[j - 1]++;
                }
                trunc = j;
            }
        }
        rep(j, trunc, n.size())
        {
            n[j] = '0';
        }
        if (n[0] >= '5')
        {
            n[0] = '0';
            cout << '1' << string(n.size(), '0') << '\n';
        }
        else
        {
            cout << n << '\n';
        }
    }
}