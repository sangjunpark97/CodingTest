#include <bits/stdc++.h>

using namespace std;

int a[100000];
int ret;

int main()
{
    int N;

    cin >> N;

    int l = 0;
    int r = 1;

    for(int i = 0; i < N; i++)
        cin >> a[i];

    while(true)
    {
        if(r >= N)
            break;

        if(a[l] != a[r])
            r++;
        else
        {
            ret += (r - l) * (r - l + 1) / 2;
         }
    }

    cout << ret;
}