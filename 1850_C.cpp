#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    for (int j = 0; j < t; j++)
    {

        string w;
        for (int i = 0; i < 8; ++i)
        {
            string l;
            cin >> l;
            for (char ch : l)
            {
                if (ch != '.')
                {
                    w += ch;
                }
            }
        }
        cout << w << '\n';
    }
}