#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
typedef long long ll;
int ct = 0;
bool twofifty = false;
int n = 0;
vector<int> main1()
{
    int lower, upper;

    cin >> n;

    vector<int> connected;
    // Find a node in cycle
    lower = 1;
    upper = n + 1;
    while (lower < upper - 1)
    {
        int mid = (lower + upper) / 2;
        cout << "? 1 " << n << ' ' << upper - mid;
        rep(i, mid, upper)
        {
            cout << ' ' << i;
        }
        cout << endl;
        ++ct;
        int res;
        cin >> res;
        if (res)
        {
            lower = mid;
        }
        else
        {
            upper = mid;
        }
    }
    connected.push_back(lower);
    rep(j, 1, 125)
    {
        lower = 1;
        upper = n + 1;
        while (lower < upper - 1)
        {
            int mid = (lower + upper) / 2;
            cout << "? " << connected.back() << " 1 " << upper - mid;
            rep(i, mid, upper)
            {
                cout << ' ' << i;
            }
            cout << endl;
            ++ct;
            int res;
            cin >> res;
            if (res)
            {
                lower = mid;
            }
            else
            {
                upper = mid;
            }
        }
        if (lower == connected[0])
        {
            break; // set a flag?
        }
        connected.push_back(lower);
    }
    if (connected.size() < 125)
    {
        return connected;
    }
    rep(r, 1, n + 1)
    {
        if (find(connected.begin(), connected.end(), r) == connected.end())
        {
            cout << "? " << r << " 125 " << connected.size();
            for (auto c : connected)
            {
                cout << ' ' << c;
            }
            cout << endl;
            ++ct;
            int res;
            cin >> res;
            if (res)
            {
                connected.push_back(r);
            }
        }
    }
    if (connected.size() < 250)
    {
        return connected;
    }
    twofifty = true;
    rep(r, 1, n + 1)
    {
        if (find(connected.begin(), connected.end(), r) == connected.end())
        {
            cout << "? " << r << " 250 " << connected.size();
            for (auto c : connected)
            {
                cout << ' ' << c;
            }
            cout << endl;
            ++ct;
            int res;
            cin >> res;
            if (res)
            {
                connected.push_back(r);
            }
        }
    }
    return connected;
}

int main()
{
    vector<int> connected = main1();
    if (1)
    {
        rep(r, 1, n + 1)
        {
            if (find(connected.begin(), connected.end(), r) == connected.end())
            {
                cout << "? " << r << " 500 " << connected.size();
                for (auto c : connected)
                {
                    cout << ' ' << c;
                }
                cout << endl;
                ++ct;
                int res;
                cin >> res;
                if (res)
                {
                    connected.push_back(r);
                }
            }
        }
    }

    cout << "! " << connected.size();
    // if (connected.size() == 480 && connected[0] == 173)
    // {
    //     cout << twofifty << ' ';
    // }
    for (auto c : connected)
    {
        cout << ' ' << c;
    }
    cout << endl;
}
