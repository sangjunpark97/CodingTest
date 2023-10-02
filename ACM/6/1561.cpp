#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

long long mp[10001];
long long N, M;

long long Check(long long mid)
{
    long long sum = M;

    for(long long i = 0; i < M; i++)
    {
        sum += mid / mp[i];
    }

    return sum >= N;
}

int main()
{
    cin >> N >> M;

    for(long long i = 0; i < M; i++)
        cin >> mp[i];

    long long r = 2000000000000;
    long long l = 0;

    long long ret = 0;
    long long sumret = 0;

    while(l <= r)
    {
        long long mid = (l + r) / 2;
        long long sum = M;

        for(long long i = 0; i < M; i++)
            sum += mid / mp[i];

        if(sum >= N)
        {
            ret = mid;
            r = mid -1;
            sumret = sum;
        }
        else
            l = mid +1;
    }

    long long k = sumret - N;

    vector<long long> v;

    for(long long i = 0; i < M; i++)
    {
        if(ret % mp[i] == 0)
            v.push_back(i + 1);
    }

    if(sumret == M)
        cout << N;
    else
        cout << v[v.size() - 1 - k];
}