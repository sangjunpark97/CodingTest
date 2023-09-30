#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N, M;

int mp[100001];
int sum1[100001];

int check(int W)
{
    int cnt = 0;

    for(int i = 0; i < N; i++)
    {
        if(cnt >= M)
            return 0;

        if(sum1[cnt] + mp[i] > W)
        {
            cnt++;
            i--;
        }
        else
            sum1[cnt]+=mp[i];
    }

    return 1;
}

int main()
{
    cin >> N >> M;

    int sum = 0;

    for(int i = 0; i < N; i++)
    {
        cin >> mp[i];
        sum += mp[i];
    }

    int l = 0;
    int r = sum;
    int ret = 2000000000;

    while(l <= r)
    {
        int mid = (l+r) / 2;

        memset(sum1, 0, sizeof(sum1));
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