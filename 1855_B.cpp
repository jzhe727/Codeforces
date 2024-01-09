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
        ll n;
        cin >> n;
        ll c = 1;
        while (1)
        {
            if (n % c != 0)
            {
                break;
            }
            ++c;
        }
        cout << c - 1 << '\n';
    }
}