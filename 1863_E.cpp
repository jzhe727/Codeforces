#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (b); ++i)

const int N = 2e5; // limit for array size
int num;           // array size
ll t[2 * N];

int height = sizeof(int) * 8 - __builtin_clz(num);
ll d[N];

void apply(int p, ll value)
{
    t[p] += value;
    if (p < num)
        d[p] += value;
}

void build(int p)
{
    while (p > 1)
        p >>= 1, t[p] = max(t[p << 1], t[p << 1 | 1]) + d[p];
}

void push(int p)
{
    for (int s = height; s > 0; --s)
    {
        int i = p >> s;
        if (d[i] != 0)
        {
            apply(i << 1, d[i]);
            apply(i << 1 | 1, d[i]);
            d[i] = 0;
        }
    }
}

void inc(int l, int r, ll value)
{
    l += num, r += num;
    int l0 = l, r0 = r;
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            apply(l++, value);
        if (r & 1)
            apply(--r, value);
    }
    build(l0);
    build(r0 - 1);
}

ll query(int l, int r)
{
    l += num, r += num;
    push(l);
    push(r - 1);
    ll res = -2e9;
    for (; l < r; l >>= 1, r >>= 1)
    {
        if (l & 1)
            res = max(res, t[l++]);
        if (r & 1)
            res = max(t[--r], res);
    }
    return res;
}

int main()
{
    fill_n(t, 2 * N, (ll)0);
    fill_n(d, N, (ll)0);
    cin.tie(0)->sync_with_stdio(0);
    int test;
    cin >> test;
    rep(i, 0, test)
    {
        int n, m, h;
        cin >> n >> m >> h;
        ll total = 0;
        vector<int> in(n);
        vector<int> out(n);
        vector<int> hours(n);
        vector<vector<int>> next(n);
        vector<ll> longest(n);
        rep(j, 0, n)
        {
            int hi;
            cin >> hi;
            hours[j] = hi;
        }
        rep(k, 0, m)
        {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            in[b] += 1;
            out[a] += 1;
            next[a].push_back(b);
        }
        rep(j, 0, n)
        {
            for (int dest : next[j])
            {
                longest[dest] = max(longest[dest], longest[j] + (hours[dest] - hours[j] + h) % h);
            }
            //     total = max(total, longest[j]);
        }
        map<ll, ll> seq;
        rep(j, 0, n)
        {
            if (out[j] == 0)
            {
                ll start = (hours[j] - (longest[j] % h) + h) % h;
                seq[start] = max(seq[start], (ll)longest[j]);
            }
        }
        // clear the tree

        num = seq.size();
        // cout << num << '\n';
        height = sizeof(int) * 8 - __builtin_clz(num);

        vector<pair<ll, ll>> seqvec(seq.begin(), seq.end());
        ll current = seqvec[0].first;
        for (int j = 0; j < num; ++j)
        {
            inc(j, j + 1, seqvec[j].second + (seqvec[j].first - current));
        }
        // cout << query(0, num) << '\n';

        total = query(0, num);

        for (int j = 1; j < num; ++j)
        {

            inc(j - 1, j, h);
            inc(0, num, -(seqvec[j].first - current));
            total = min(total, query(0, num));
            // cout << seqvec[j].first << ' '
            //      << query(0, num) << '\n';
            current = seqvec[j].first;
        }
        // total = max(total, longest[j]);
        cout << total << '\n';
        // clear the tree
        fill_n(t, 2 * num, (ll)0);
        fill_n(d, num, (ll)0);
    }
}