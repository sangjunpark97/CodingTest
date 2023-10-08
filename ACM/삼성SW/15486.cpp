#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N;
int t[1500000];
int p[1500000];
int dp[1500000][51];

int go(int idx, int delay)
{
    if(idx == N)
        return 0;
    else
    {
        int &ret = dp[idx][delay];

        if(~ret)
            return ret;
        
        int tmp;

        if(delay == 0 && (idx + t[idx]) <= N)
        {
            tmp = max(go(idx + 1, t[idx] - 1) + p[idx], go(idx + 1, 0));
        }
        else
        {
            if(delay == 0)
                tmp = go(idx + 1, 0);
            else
                tmp = go(idx + 1, delay - 1);
        }


        return ret = tmp;
    }
}

int main()
{
    fastio;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> t[i] >> p[i];
    }

    memset(dp, -1, sizeof(dp));

    cout << go(0, 0);
}