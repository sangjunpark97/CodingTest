#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N, M, C;
int stone[24];
int dp[24][1 << 14][24];


int go(int Bag, int ston, int Cap)
{
    if(Bag >= M)
        return 0;
    else
    {
        int& ret = dp[Bag][ston][Cap];

        if(ret != 0)
            return ret;

        ret = max(ret, go(Bag + 1, ston, C));

        for(int i = 0; i < N; i++)
        {
            bool bBefore = ston & (1 << i);
            bool bCap = Cap - stone[i] >= 0;

            if(!bBefore && bCap) ret = max(ret, go(Bag, ston | (1 << i), Cap - stone[i]) + 1);
        }

        return ret;
    }
}

int main()
{
    cin >> N >> M >> C;

    for(int i = 0; i < N; i++)
        cin >> stone[i];
    
    cout << go(0,0,C);
}