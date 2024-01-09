#include <bits/stdc++.h>

using namespace std;
#define rep(i, a, b) for (int i = a; i < b; ++i)
typedef long long ll;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    rep(test, 0, t)
    {
        int n;
        cin >> n;
        vector<ll> a;
        vector<vector<ll>> adj(n);
        rep(i, 0, n)
        {
            int ai;
            cin >> ai;
            a.push_back(ai);
        }
        rep(i, 0, n - 1)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for (auto &v : adj)
        {
            sort(v.begin(), v.end());
        }
        vector<vector<ll>> cost(adj);
        vector<vector<ll>> size(adj);
        rep(i, 0, n)
        {
            rep(j, 0, adj[i].size())
            {
                cost[i][j] = -1;
                size[i][j] = -1;
            }
        }
        vector<int> done(n);
        vector<int> missing(n);
        vector<ll> ans(n);
        vector<int> stack;
        rep(i, 0, n)
        {
            missing[i] = adj[i].size();
            if (adj[i].size() == 1)
            {
                stack.push_back({i});
            }
        }
        while (stack.size() > 0)
        {
            int c = stack.back();
            stack.pop_back();
            if (done[c] == 2)
            {
                continue;
            }
            if (missing[c] == 1)
            {

                // find the missing
                int dest = -1;
                ll c_dest_cost = 0;
                ll c_dest_size = 1;
                int dest_loc = -1;
                rep(i, 0, adj[c].size())
                {
                    int v = adj[c][i];
                    if (done[v] == 0)
                    {
                        assert(dest == -1);
                        dest = v;
                        dest_loc = i;
                    }
                    else
                    {
                        int c_loc = lower_bound(adj[v].begin(), adj[v].end(), c) - adj[v].begin();
                        assert(size[v][c_loc] != -1);
                        c_dest_cost += size[v][c_loc] * (a[c] ^ a[v]) + cost[v][c_loc];
                        c_dest_size += size[v][c_loc];
                    }
                }
                assert(dest != -1);
                size[c][dest_loc] = c_dest_size;
                cost[c][dest_loc] = c_dest_cost;
                if (--missing[dest] == 1)
                {
                    stack.push_back(dest);
                }
                done[c] = 1;
            }
            else if (missing[c] == 0)
            {
                ll c_all_cost = 0;
                ll c_all_size = 1;
                rep(i, 0, adj[c].size())
                {
                    int v = adj[c][i];
                    assert(done[v] != 0);
                    assert(missing[v] < 2);
                    int c_loc = lower_bound(adj[v].begin(), adj[v].end(), c) - adj[v].begin();
                    c_all_cost += size[v][c_loc] * (a[c] ^ a[v]) + cost[v][c_loc];
                    c_all_size += size[v][c_loc];
                }
                ans[c] = c_all_cost;
                rep(i, 0, adj[c].size())
                {
                    int v = adj[c][i];
                    if (missing[v] == 1)
                    {
                        int c_loc = lower_bound(adj[v].begin(), adj[v].end(), c) - adj[v].begin();
                        ll c_v_cost = c_all_cost - size[v][c_loc] * (a[c] ^ a[v]) - cost[v][c_loc];
                        ll c_v_size = c_all_size - size[v][c_loc];
                        cost[c][i] = c_v_cost;
                        size[c][i] = c_v_size;
                        missing[v]--;
                        stack.push_back(v);
                    }
                }
                done[c] = 2;
            }
        }
        bool debug = false;
        if (debug)
        {
            cout << "DEBUG\n";
            rep(i, 0, n)
            {
                rep(j, 0, adj[i].size())
                {
                    cout << "-- " << i << ' ' << adj[i][j] << '\n';
                    cout << cost[i][j] << ' ' << size[i][j] << '\n';
                }
            }
            cout << "DEBUG\n";
        }
        rep(i, 0, n)
        {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}