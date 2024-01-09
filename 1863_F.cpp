#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
#define rep(i, a, b) for (int i = a; i < (b); ++i)

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    rep(t, 0, test)
    {
        int n;
        cin >> n;
        vector<ull> nums;
        vector<ull> lmask(n);
        vector<ull> rmask(n);
        vector<bool> lall(n);
        vector<bool> rall(n);
        rep(i, 0, n)
        {
            ull a;
            cin >> a;
            nums.push_back(a);
        }
        // prefix xor
        vector<ull> pre;
        pre.push_back(0); // exclusive
        rep(i, 0, n)
        {
            pre.push_back(pre[i] ^ nums[i]);
        }
        for (int len = n - 1; len >= 0; --len)
        {
            rep(l, 0, n - len)
            {
                int r = l + len; // l, r inclusive
                ull cxor = pre[l] ^ pre[r + 1];
                if ((cxor & lmask[l]) || (cxor & rmask[r]) || lall[l] || rall[r] || (l == 0 and r == n - 1))
                {
                    if (cxor == 0)
                    {
                        lall[l] = true;
                        rall[r] = true;
                    }
                    else
                    {
                        lmask[l] |= (ull)1 << (63 - __builtin_clzll(cxor));
                        rmask[r] |= (ull)1 << (63 - __builtin_clzll(cxor));
                    }
                    if (len == 0)
                    {
                        cout << '1';
                    }
                }
                else if (len == 0)
                {
                    cout << '0';
                }
            }
        }
        cout << '\n';
    }
}