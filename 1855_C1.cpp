#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (b); ++i)

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(ti, 0, t)
    {
        int neg = 0;
        int negp;
        int pos = 0;
        int posp;
        int n;
        cin >> n;
        vector<int> nums;
        rep(j, 0, n)
        {
            int a;
            cin >> a;
            nums.push_back(a);
            neg = min(neg, a);
            if (neg == a)
            {
                negp = j;
            }
            pos = max(pos, a);
            if (pos == a)
            {
                posp = j;
            }
        }
        int mc = 0;
        vector<pair<int, int>> moves;
        if (pos == 0 && neg == 0)
        {
            cout << 0 << endl;
            continue;
        }
        if (pos > abs(neg))
        {
            while (nums[0] < pos)
            {
                mc++;
                moves.push_back({1, posp + 1});
                nums[0] += pos;
            }
            rep(i, 1, n)
            {
                while (nums[i] < nums[i - 1])
                {
                    mc++;
                    moves.push_back({i + 1, i});
                    nums[i] += nums[i - 1];
                }
            }
        }
        else
        {
            while (nums[n - 1] > neg)
            {
                mc++;
                moves.push_back({n, negp + 1});
                nums[n - 1] += neg;
            }
            for (int i = n - 2; i >= 0; --i)
            {
                while (nums[i] > nums[i + 1])
                {
                    mc++;
                    moves.push_back({i + 1, i + 2});
                    nums[i] += nums[i + 1];
                }
            }
        }
        cout << mc << endl;
        for (auto move : moves)
        {
            cout << move.first << ' ' << move.second << ' ';
        }
        cout << endl;
    }
}