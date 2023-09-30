#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mp[1001];
int ret[1001];

int main()
{
    int N;

    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> mp[i];

    int len = 0;

    for(int i = 0; i < N; i++)
    {
        auto lower = lower_bound(ret, ret + len, mp[i]);

        if(*lower == 0) len++;
        *lower = mp[i];
    }

    int cnt = 0;
    for(int i = 0; ret[i] != 0; i++)
        cnt++;

    cout << cnt;
}