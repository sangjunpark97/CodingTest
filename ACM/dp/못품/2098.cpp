#include <bits/stdc++.h>

using namespace std;

int dp[16][1 << 16];
int N;
int table[16][16];

int go(int now, int visited)
{
    if(visited == (1 << N) -1)
    {
        return table[now][0] == 0 ? 987654321 : table[now][0];
    }

    int &ret = dp[now][visited];
    
    if(ret!=-1)
        return ret;

    ret = 987654321;

    for(int i = 0; i < N; i++)
    {   
        if(table[now][i] == 0)
            continue;

        if((visited & (1 << i)) == 0)
            ret = min(ret, go(i, visited | (1 << i)) + table[now][i]);
    }

    return ret;
}

int main()
{
    cin >> N;

    memset(dp, -1, sizeof(dp));

    for(int i = 0; i < N ; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> table[i][j];
        }
    }

    int ret = go(0,1);

    cout << ret;
}