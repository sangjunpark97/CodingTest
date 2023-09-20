#include <bits/stdc++.h>

using namespace std;

int a[12];
int v[4];
int N;
int small = 2000000000;
int big = -1000000001;

void go(int cnt, int res)
{
    if(cnt == N - 1)
    {
        big = max(big, res);
        small = min(small, res);
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            if(v[i])
            {
                int tmp = res;
                
                v[i]--;
                
                if(i == 0)
                    res = res + a[cnt + 1]; 
                else if(i == 1)
                    res = res - a[cnt + 1];
                else if(i == 2)
                    res = res * a[cnt + 1];
                else
                    res = res / a[cnt + 1];

                go(cnt+1, res);

                res = tmp;
                
                v[i]++;
            }
        }
    }
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
        cin >> a[i];

    for(int i = 0; i < 4; i++)
        cin >> v[i];

    go(0, a[0]);

    cout << big << "\n" << small;
}