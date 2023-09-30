#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    long long x, y;

    cin >> x >> y;

    long long l = 0;
    long long r = 1e9;
    long long start = y * 100 / x;

    long long ret = 1e13;

    while(l <= r)
    {
        long long mid = (l + r) / 2;

        if((y + mid) * 100 / (x + mid) > start)
        {
            r = mid - 1;
            ret = min(ret, mid);
        }
        else
            l = mid + 1;
    }

    if(ret == 1e13)
        cout << "-1";
    else
        cout << ret;
}