#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)

int main()
{
    vector<int> nums;
    cout << 1 << endl;
    cout << 1000 << endl;
    rep(i, -999'999'999, 999'999'000)
    {
        rep(j, 0, -999'999'000 - i)
        {
            nums.push_back(i);
        }
    }
    random_shuffle(nums.begin(), nums.end());
    rep(i, 0, nums.size() - 1)
    {
        cout << nums[i] << ' ';
    }
    cout << nums.back();
    cout << endl;
}

// 1857/challenge/217654856