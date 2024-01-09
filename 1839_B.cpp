
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool rev(pair<ll, ll> a, pair<ll, ll> b)
{
    return a > b;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        map<ll, vector<ll>> lamps;
        for (int j = 0; j < n; j++)
        {
            ll a, b;
            cin >> a >> b;
            lamps[a].push_back(b);
        }
        ll total = 0;
        for (auto p : lamps)
        {
            sort(p.second.begin(), p.second.end(), greater<ll>());
            int num = min(p.first, (ll)p.second.size());
            for (int k = 0; k < num; k++)
            {
                total += p.second[k];
            }
        }
        cout << total << endl;
    }
}