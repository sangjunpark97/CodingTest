#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

double A, B;
double dp[20][20][20];

double go(int cnt, int a, int b)
{
    if(cnt == 18)
    {
        if(a == 2 || a == 3 || a == 5 || a == 7 || a == 11 || a == 13 || a == 17 || b == 2 || b == 3 || b == 5 || b == 7 || b == 11 || b == 13 || b == 17)
            return 1;
        else
            return 0;
    }
    else
    {
        double & ret = dp[cnt][a][b];

        if(ret > -0.5)
            return ret;

        ret = 0;

        ret += go(cnt + 1, a + 1, b + 1) * A * B;
        ret += go(cnt + 1, a + 1, b) * A * (1 - B);
        ret += go(cnt + 1, a, b + 1) * (1 - A) * B;
        ret += go(cnt + 1, a, b) * (1 - A) * (1 - B);

        return ret;
    }
}

int main()
{
    cin >> A >> B;

    memset(dp, -1, sizeof(dp));
    A = A /100;
    B = B /100;

    cout << go(0,0,0);
}