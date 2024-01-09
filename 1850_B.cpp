#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int best = 0;
        int m;
        for (int j = 0; j < n; j++)
        {
            int a, b;
            cin >> a >> b;
            if (a <= 10)
            {
                best = max(best, b);
                if (best == b)
                    m = j;
            }
        }
        cout << m + 1 << '\n';
    }
}