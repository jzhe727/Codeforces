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
        int mismatched = 0;
        for (int j = 1; j <= n; j++)
        {
            int c;
            cin >> c;
            if (j == c)
                mismatched += 1;
        }
        cout << (mismatched + 1) / 2 << "\n";
    }
}