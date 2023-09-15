#include <bits/stdc++.h>

using namespace std;

long long dp[31][31];

long long go(long long one, long long half)
{
    if(one == 0 && half == 0)
        return 1;
    
    long long &ret = dp[one][half];

    if(~ret)
        return ret;

    if(one == 0)
        return ret = go(one, half - 1);
    else if(half == 0)
        return ret = go(one -1, half + 1);
    else
        return ret = go(one -1, half + 1) + go(one, half - 1);
}

int main()
{
    long long N = 1;

    memset(dp, -1, sizeof(dp));

    while(true)
    {
        cin >> N;

        if(N == 0)
            break;

        if(dp[N][0] != -1)
            cout << dp[N][0] << "\n";
        else
            cout << go(N,0) << "\n";
    }
}