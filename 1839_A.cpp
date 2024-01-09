#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int det(int n, int k)
{
    int to_fill = n >> 1;
    int side_one = to_fill / k + (to_fill % k != 0);
    int side_zeroes = to_fill - (side_one * (k - 1)) - 1;
    if (side_zeroes * 2 + (n % 2) >= k)
    {
        return side_one * 2 + 1;
    }
    else
    {
        return side_one * 2;
    }
}

int cieldiv(int a, int b)
{
    return a / b + (a % b != 0);
}

int det2(int n, int k)
{
    return (cieldiv(n - 1, k)) + 1;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n, k;
        cin >> n >> k;
        cout << det2(n, k) << endl;
    }
}