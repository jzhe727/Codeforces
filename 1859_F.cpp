// We need a LCA network
// We also need to find "close" T nodes
// Each node also needs a way to find distance to any ancestor (sparse table)
#pragma GCC target("avx2,lzcnt")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
#define sz(V) (int)V.size()
#define rep(i, a, b) for (int i = a; i < (b); ++i)
typedef vector<int> vi;
typedef unsigned long long ll;

const ll MAX = (ll)INT32_MAX * (ll)1'000'000;

template <class T>

struct RMQ
{
    vector<vector<T>> jmp;
    RMQ(const vector<T> &V) : jmp(1, V)
    {
        for (int pw = 1, k = 1; pw * 2 <= sz(V); pw *= 2, ++k)
        {
            jmp.emplace_back(sz(V) - pw * 2 + 1);
            rep(j, 0, sz(jmp[k]))
                jmp[k][j] = min(jmp[k - 1][j], jmp[k - 1][j + pw]);
        }
    }
    T query(int a, int b)
    {
        int dep = 31 - __builtin_clz(b - a);
        return min(jmp[dep][a], jmp[dep][b - (1 << dep)]);
    }
};

struct LCA
{
    int T = 0;
    vi time, path, ret;
    RMQ<int> rmq;
    LCA(vector<vi> &C) : time(sz(C)), rmq((dfs(C, 0, -1), ret)) {}
    void dfs(vector<vi> &C, int v, int par)
    {
        time[v] = T++;
        for (int y : C[v])
            if (y != par)
            {
                path.push_back(v), ret.push_back(time[v]);
                dfs(C, y, v);
            }
    }
    int lca(int a, int b)
    {
        if (a == b)
            return a;
        tie(a, b) = minmax(time[a], time[b]);
        return path[rmq.query(a, b)];
    }
};

struct RootDist
{
    vector<ll> depth;
    RootDist(const vector<vector<pair<int, ll>>> &C) : depth(sz(C))
    {
        dfs(C, 0, -1, 0);
    }
    void dfs(const vector<vector<pair<int, ll>>> &C, int v, int par, ll d)
    {
        depth[v] = d;
        for (auto y : C[v])
            if (y.first != par)
            {
                dfs(C, y.first, v, d + y.second);
            }
    }
    ll get(int a) { return depth[a]; }
    ll d(int a, int b) // d only works if they are children/ancestor, a is child and b is ancestor
    {
        return depth[a] - depth[b];
    }
};

struct NearestCourse
{
    vector<ll> ret;
    NearestCourse(vector<vector<pair<int, ll>>> &C, vector<vector<pair<int, ll>>> &O, vector<bool> &A) : ret(sz(C))
    {
        dfs(C, O, 0, -1, MAX, A);
        pushdown(C, O, 0, -1, A);
    }
    ll dfs(vector<vector<pair<int, ll>>> &C, vector<vector<pair<int, ll>>> &O, int v, int par, ll close, vector<bool> &A)
    {
        if (A[v])
        {
            close = 0;
        }
        rep(i, 0, sz(C[v]))
        {
            pair<int, ll> y = C[v][i];
            pair<int, ll> x = O[v][i];
            if (y.first != par)
            {
                close = min(dfs(C, O, y.first, v, close + y.second + x.second, A) + y.second + x.second, close);
            }
        }

        ret[v] = close;
        return close;
    }
    void pushdown(vector<vector<pair<int, ll>>> &C, vector<vector<pair<int, ll>>> &O, int v, int par, vector<bool> &A)
    {
        ll close = ret[v];
        rep(i, 0, sz(C[v]))
        {

            pair<int, ll> y = C[v][i];
            pair<int, ll> x = O[v][i];
            if (y.first != par)
            {
                ret[y.first] = min(ret[y.first], close + y.second + x.second);
                pushdown(C, O, y.first, v, A);
            }
        }
    }
    ll get(int a) { return ret[a]; }
};

struct Optimal
{
    vector<vector<pair<int, ll>>> &O;
    vector<vector<pair<int, ll>>> &C;
    vector<bool> &A;
    RootDist Odist;
    RootDist Cdist;
    NearestCourse nc;
    vector<vector<pair<ll, int>>> jmpu; // jmp[v][i] the up/down nearest course and then the exclusive ancestor
    vector<vector<pair<ll, int>>> jmpd;
    vi treedepth;
    // vi parent;
    Optimal(vector<vector<pair<int, ll>>> &Oin, vector<vector<pair<int, ll>>> &Cin, vector<bool> &Ain)
        : O(Oin), C(Cin), A(Ain), Odist(Oin), Cdist(Cin), nc(Cin, Oin, Ain), jmpu(sz(Cin)), jmpd(sz(Cin)),
          treedepth(sz(Cin)) //, parent(sz(Cin))
    {
        dfs(0, -1, 0);
    }
    void dfs(int v, int par, int td)
    {
        treedepth[v] = td;
        // parent[v] = par;
        jmpu[v].push_back({nc.get(v), par}); // jmpu is exclusive
        jmpd[v].push_back({nc.get(v), v});   // jmpd is inclusive
        int c = par;
        int h = 0;
        while (c != -1 && sz(jmpu[c]) > h)
        {
            ll up = min(jmpu[v][h].first, Odist.d(v, c) - Cdist.d(v, c) + jmpu[c][h].first);
            ll down = min(jmpd[v][h].first + Odist.d(jmpd[v][h].second, jmpd[c][h].second) - Cdist.d(jmpd[v][h].second, jmpd[c][h].second), jmpd[c][h].first);
            int d = jmpd[c][h].second;
            c = jmpu[c][h].second;
            jmpu[v].push_back({up, c});
            jmpd[v].push_back({down, d});
            ++h;
        }
        rep(i, 0, sz(C[v]))
        {
            pair<int, ll> y = C[v][i];
            if (y.first != par)
            {
                dfs(y.first, v, td + 1);
            }
        }
    }
    ll query(int a, int b, int c) // from a, to lca b, to c
    {
        int upd = treedepth[a] - treedepth[b] + 1;
        ll upmin = MAX;
        int dep = 31 - __builtin_clz(upd);
        int cur = a;
        while (upd != 0)
        {
            upmin = min(upmin, Odist.d(a, cur) - Cdist.d(a, cur) + jmpu[cur][dep].first);
            cur = jmpu[cur][dep].second;
            upd = upd - (1 << dep);
            dep = 31 - __builtin_clz(upd);
        }
        ll downmin = MAX;
        int downd = treedepth[c] - treedepth[b] + 1;
        dep = 31 - __builtin_clz(downd);
        cur = c;
        while (downd != 0)
        {
            int next = jmpu[cur][dep].second;
            downmin = min(downmin, Odist.d(jmpd[cur][dep].second, b) - Cdist.d(jmpd[cur][dep].second, b) + jmpd[cur][dep].first);
            cur = next;
            downd = downd - (1 << dep);
            dep = 31 - __builtin_clz(downd);
        }
        ll best = min(upmin + Cdist.d(a, b) + Cdist.d(c, b), downmin + Odist.d(a, b) + Cdist.d(c, b));
        return best;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;

    rep(test, 0, t)
    {
        int n;
        ll T;
        cin >> n >> T;
        vector<vector<pair<int, ll>>> O(n);
        rep(i, 0, n - 1)
        {
            int u, v, w;
            cin >> u >> v >> w;
            u--;
            v--;
            O[u].push_back({v, w});
            O[v].push_back({u, w});
        }
        vector<bool> A(n);
        rep(i, 0, n)
        {
            char cr;
            cin >> cr;
            if (cr == '1')
            {
                A[i] = true;
            }
        }
        int q;
        cin >> q;
        vector<pair<int, int>> queries;
        vector<ll> ans(q);
        rep(i, 0, q)
        {
            int a, c;
            cin >> a >> c;
            a--;
            c--;
            queries.push_back({a, c});
        }
        vector<vector<int>> adj(n);
        rep(v, 0, n)
        {
            for (auto &y : O[v])
            {
                adj[v].push_back(y.first);
            }
        }
        LCA lca(adj);
        RootDist rd(O);
        rep(i, 0, q)
        {
            int a = queries[i].first;
            int c = queries[i].second;
            int b = lca.lca(a, c);
            ans[i] = rd.d(a, b) + rd.d(c, b);
        }

        rep(tr, 1, 20)
        {
            int skill = 1 << tr;
            vector<vector<pair<int, ll>>> C(O);
            rep(v, 0, n)
            {
                for (auto &y : C[v])
                {
                    y.second = (y.second + skill - 1) / skill;
                }
            }
            Optimal optimal(O, C, A);
            rep(i, 0, q)
            {
                int a = queries[i].first;
                int c = queries[i].second;
                int b = lca.lca(a, c);
                ans[i] = min(optimal.query(a, b, c) + (ll)tr * T, ans[i]);
            }
        }
        rep(i, 0, q)
        {
            cout << ans[i] << '\n';
        }
    }
}