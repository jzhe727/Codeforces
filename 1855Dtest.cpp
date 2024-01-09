#pragma GCC optimize("Ofast")
#pragma GCC target("avx2") //,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    auto start = chrono::high_resolution_clock::now();
    bitset<200'000> r;
    r[0] = 1;
    for (int i = 0; i < n; i++)
    {
        r |= (r << i);
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    cout << r.all() << endl;

    // To get the value of duration use the count()
    // member function on the duration object
    cout << duration.count() << endl;
}