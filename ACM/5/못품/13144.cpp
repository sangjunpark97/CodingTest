#include <bits/stdc++.h>

using namespace std;

long long a[100000];
long long cnt[100001];
long long ret;

int main()
{
    long long N;

    cin >> N;

    long long l = 0;
    long long r = 1;

    for(long long i = 0; i < N; i++)
        cin >> a[i];

    cnt[a[l]]++;

    while(r < N)
    {
        
        if(cnt[a[r]] == 0)
        {
            cnt[a[r++]]++;
        }
        else
        {
            ret += r - l;
            cnt[a[l++]]--;

            if(l == r)
            {
                cnt[a[r]]++;
                r++;
            }
        }
    }

    ret+= (r - l)*(r -l +1) / 2;

    cout << ret;
}