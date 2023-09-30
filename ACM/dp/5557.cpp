#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

long long mp[101];
long long dp[101][21];
long long N;

long long go(long long idx, long long value)
{
    if(idx == N - 2)
    {
        if(value == mp[N -1])
            return 1;
        else
            return 0;
    }
    else if(value > 20 || value < 0)
        return 0;
    else
    {
        long long &ret = dp[idx][value];

        if(ret != -1)
            return ret;

        ret = 0;

        ret += go(idx+1, value + mp[idx + 1]);
        ret += go(idx+1, value - mp[idx + 1]);

        return ret;
    }
}

int main()
{
    cin >> N;

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < N; i++)
    {
        cin >> mp[i];
    }

    cout << go(0, mp[0]) << "\n";
}