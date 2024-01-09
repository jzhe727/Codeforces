#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a;
    vector<int> b;
    for (int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai;
        a.push_back({ai, i + 1});
    }
    for (int i = 0; i < m; ++i)
    {
        int bi;
        cin >> bi;
        b.push_back(bi);
    }
    vector<int> fastest(1 << m, INT32_MAX);
    vector<int> prevprog(1 << m); // programmers
    vector<int> prev(1 << m, -1); // task
    sort(a.begin(), a.end());
    // vector<
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0}); // first number exclusive of currently used programmers
    fastest[0] = 0;

    vector<vector<pair<int, int>>> compProj(m, vector<pair<int, int>>(n));
    for (int i = 0; i < m; ++i)
    {
        for (int j = n - 1; j >= 0; --j)
        {
            int includecur = j + (b[i] + a[j].first - 1) / a[j].first;
            if (j == n - 1)
            {
                compProj[i][j] = {includecur, j};
            }
            else
            {
                if (compProj[i][j + 1].first > includecur)
                {
                    compProj[i][j] = {includecur, j};
                }
                else
                {
                    compProj[i][j] = compProj[i][j + 1];
                }
            }
        }
    }

    while (pq.size() > 0)
    {
        int cur, mask;
        cur = pq.top().first;
        mask = pq.top().second;
        pq.pop();
        if (cur != fastest[mask] || cur >= n)
        {
            continue;
        }
        for (int i = 0; i < m; ++i)
        {
            if (!((mask >> i) & 1))
            {
                int nextmask = mask | (1 << i);
                int nextcur = compProj[i][cur].first;
                if (nextcur < fastest[nextmask])
                {
                    fastest[nextmask] = nextcur;
                    pq.push({nextcur, nextmask});
                    prev[nextmask] = i;
                    prevprog[nextmask] = compProj[i][cur].second;
                }
            }
        }
    }

    vector<vector<int>> projs(m);
    if (fastest[(1 << m) - 1] > n)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        int c = n - 1;
        int cmask = (1 << m) - 1;
        while (cmask)
        {
            int nmask = cmask & (~(1 << prev[cmask]));
            int last = prevprog[cmask];
            for (; c >= last; --c)
            {
                projs[prev[cmask]].push_back(a[c].second);
            }
            cmask = nmask;
        }
        for (auto &proj : projs)
        {
            cout << proj.size();
            for (auto p : proj)
            {
                cout << ' ' << p;
            }
            cout << endl;
        }
    }
}
