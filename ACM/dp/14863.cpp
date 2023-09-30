#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N, K;
int dp[101][100001];
int dobo[2][101];
int jajungu[2][101];

int go(int cnt, int remain)
{
    if(remain < 0)
        return -987654321;
    else if(cnt == N)
        return 0;
    else
    {
        int& ret = dp[cnt][remain];

        if(ret != -1)
            return ret;
        
        return ret = max(go(cnt + 1, remain - dobo[0][cnt]) + dobo[1][cnt] , go(cnt + 1, remain - jajungu[0][cnt]) + jajungu[1][cnt]);
    }
}

int main()
{
    cin >> N >> K;

    for(int i = 0 ; i<N; i++)
    {
        cin >> dobo[0][i] >> dobo[1][i] >> jajungu[0][i] >> jajungu[1][i];
    }

    memset(dp, -1, sizeof(dp));
    cout << go(0, K);
}