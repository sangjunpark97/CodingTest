#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int p[30];
int h[30];
int dp[100];

int main()
{
    int N;

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> p[i];

    for(int i = 0; i < N; i++)
        cin >> h[i];

    for(int i = 0; i < N; i++)
    {
        for(int j = 99; j >= p[i]; j--)
        {
            dp[j] = max(dp[j], h[i] + dp[j - p[i]]);
        }
    }

    cout << dp[99];
}
