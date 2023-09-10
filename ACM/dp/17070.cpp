#include <bits/stdc++.h>

using namespace std;

int N;
int dp[16][16][3];
int mp[16][16];

int go(int y, int x, int stat)
{
    if(stat == 0)
    {
        if(mp[y][x])
            return 0;
    }
    else if(stat ==1)
    {
        if(mp[y - 1][x] || mp[y][x] || mp[y][x - 1])
            return 0;
    }
    else if(stat ==2)
    {
        if(mp[y][x])
            return 0;
    }

    if(y == N - 1 && x == N -1)
        return 1;
    
    int &ret = dp[y][x][stat];

    if(ret != -1)
        return ret;

    ret = 0;

    if(stat == 0)
    {
        if(x + 1 < N)
            ret += go(y, x + 1, 0);
        
        if(x + 1 < N && y + 1 < N)
            ret += go(y +1, x + 1, 1);
    }
    else if(stat == 1)
    {
        if(x + 1 < N)
            ret += go(y, x + 1, 0);
        
        if(x + 1 < N && y + 1 < N)
            ret += go(y + 1, x + 1, 1);
    
        if(y + 1 < N)
            ret += go(y + 1, x, 2);
    }
    else if(stat == 2)
    {
        if(x + 1 < N && y + 1 < N)
            ret += go(y + 1, x + 1, 1);

        if(y + 1 < N)
            ret += go(y + 1, x, 2);
    }

    return ret;
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> mp[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));
    go(0,1,0);

    cout << max(0,dp[0][1][0]) + max(0,dp[0][1][1]) +max(0,dp[0][1][2]);
}