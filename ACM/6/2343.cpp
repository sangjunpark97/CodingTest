#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mp[100001];
int ti[100001];
int N,M;

int check(int t)
{
    int idx = 0;

    for(int i = 0; i < N; i++)
    {
        if(ti[idx] + mp[i] > t)
        {
            idx++;
            i--;
        }
        else
            ti[idx] += mp[i];

        if(idx >= M)
            return 0;
    }

    return 1;
}

int main()
{
    fastio;

    cin >> N >> M;

    int sum = 0;

    for(int i = 0; i < N; i++)
    {
        cin >> mp[i];

        sum+=mp[i];
    }

    int l = 0;
    int r = sum;

    int ret = 987654321;

    while(l <= r)
    {
        int mid = (l+r) / 2;

        memset(ti, 0, sizeof(ti));

        if(check(mid))
        {
            ret = min(ret, mid);

            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    cout << ret;
}