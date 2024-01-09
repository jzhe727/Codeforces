#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test)
    {
        map<int, int> last_seen;
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        arr.reserve(n);
        vector<int> left(k + 1, -1);
        vector<int> right(k + 1, -1);

        vector<bool> seen(k + 1);
        rep(i, 0, n)
        {
            int a;
            cin >> a;
            arr.push_back(a);
        }
        int max = 0;
        rep(i, 0, n)
        {
            int a = arr[i];
            seen[a] = true;
            while (max <= a)
            {
                left[max] = i;
                max++;
            }
        }
        max = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int a = arr[i];
            while (max <= a)
            {
                right[max] = i;
                max++;
            }
        }
        rep(i, 1, k + 1)
        {
            if (!seen[i])
            {
                cout << 0 << ' ';
            }
            else
            {
                cout << (right[i] - left[i] + 1) * 2 << ' ';
            }
        }
        cout << '\n';
    }
}