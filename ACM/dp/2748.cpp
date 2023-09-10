#include <bits/stdc++.h>

using namespace std;

long long dp[100];

long long fibo(long long i)
{
    if(i < 0)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    return dp[i] = fibo(i-1) + fibo(i-2);
}

int main()
{
    memset(dp, -1, sizeof(dp));
    int n;

    cin >> n;

    dp[0] = 0;
    dp[1] = 1;

    long long ret = fibo(n);

    cout << ret;
}