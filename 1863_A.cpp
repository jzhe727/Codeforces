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
        int n, a, q;
        cin >> n >> a >> q;
        int b = a;
        bool force = false;
        bool poss = false;
        if (b == n)
        {
            poss = true;
        }
        if (a == n)
        {
            force = true;
        }
        rep(j, 0, q)
        {
            char c;
            cin >> c;
            if (c == '+')
            {
                a++;
                b++;
            }
            else
            {
                a--;
            }
            if (b == n)
            {
                poss = true;
            }
            if (a == n)
            {
                force = true;
            }
        }
        if (force)
        {
            cout << "YES\n";
        }
        else if (poss)
        {
            cout << "MAYBE\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}