#include <bits/stdc++.h>

using namespace std;
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int dp[10001];
int n, m;
vector<pair<int, int>> v;

int go(int value)
{
    int &ret = dp[value];

    if(ret != 0)
        return ret;
    else
    {
        for(int i = 0; i < v.size(); i++)
        {
            if(value - v[i].second >= 0)
                ret = max(ret, v[i].first + go(value - v[i].second));
        }
    }

    return ret;
}

int main()
{
    while(true)
    {
        int m1, m2;

        scanf("%d %d.%d", &n, &m1, &m2);

        m = m1 * 100 + m2;

        if(n == 0 && m == 0)
            break;

        memset(dp, 0, sizeof(dp));
        v.clear();
        
        for(int i = 0; i < n; i++)
        {
            int c;

            scanf("%d %d.%d", &c, &m1, &m2);

            v.push_back(pair<int, int>(c,(int)(m1 * 100 + m2)));
        }

        go(m);

        cout << dp[m] << "\n";
    }
}