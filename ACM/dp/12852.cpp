#include <bits/stdc++.h>

using namespace std;

int dp[1000001];
int mp[1000001];
int N;
int gcnt = 987654321;

int go(int num)
{
    if(num == 1)
        return 0;
    else if(num < 1)
        return 987654321;
    else
    {
        int& ret = dp[num];

        if(~ret)
            return dp[num];
        
        int ret1 = 987654321;
        int ret2 = 987654321;
        int ret3 = 987654321;
        
        if(num % 3 == 0 && num % 2 == 0)
        {
            ret1 = go(num / 3) + 1;
            ret2 = go(num / 2) + 1;
        }
        else if(num % 3 == 0)
            ret1 = go(num/3) + 1;
        else if(num % 2 == 0)
            ret2 = go(num / 2) + 1;
        
        ret3 = go(num -1) + 1;

        ret = min(ret1,min(ret2,ret3));

        if(ret == ret1)
            mp[num] = num / 3;
        else if(ret == ret2)
            mp[num] = num / 2;
        else
            mp[num] = num -1;

        return ret;
    }
}

int main()
{
    cin >> N;

    memset(dp, -1, sizeof(dp));

    go(N);

    dp[1] = 0;
    cout << dp[N] << "\n";

    int M = N;
    cout << M << " ";
    
    while(M > 1)
    {
        cout << mp[M] << " ";
        M = mp[M];
    }
}