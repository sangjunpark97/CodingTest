#include <bits/stdc++.h>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int dp[10001];

int main()
{
    fastio;
    
    while(true)
    {
        int n, a, b, m;

        scanf("%d %d.%d", &n, &a, &b);

        m = a*100 + b;

        if(n == 0 && m == 0)
            break;

        memset(dp, 0, sizeof(dp));

        for(int i = 0; i < n; i++)
        {
            int c, p, q,w;

            scanf("%d %d.%d\n", &c, &q, &w);

            p = q * 100 + w;

            for(int j = p; j <= m; j++)
            {
                dp[j] = max(dp[j], dp[j - p] + c);
            }
        }

        cout << dp[m] << "\n";
    }
}