#include <bits/stdc++.h>
using namespace std;

int N;
int mp[20][20];
int mp2[20][20];
int ret = 987654321;

int main()
{
    cin >> N;

    for(int y = 0; y< N; y++)
    {
        string s;
        cin >> s;
        for(int x = 0; x < N; x++)
        {
            if(s[x] == 'T')
                mp[y][x] = 1;
            if(s[x] == 'T')
                mp2[y][x] = 1;
        }
    }
    
    for(int i = 0; i < pow(2, N); i++)
    {
        for(int t = 0; t < N; t++)
        {
            if(i & (1 << t))
            {
                for(int y= 0; y < N; y++)
                {
                    mp[y][t]^=1;
                }
            }
        }

        int retCnt = 0;

        for(int y = 0; y < N; y++)
        {
            int cnt = 0;

            for(int x = 0; x < N; x++)
            {
                if(mp[y][x] == 0)
                    cnt++;
            }

            if(cnt <= N / 2)
            {
                for(int x = 0; x < N; x++)
                    mp[y][x]^=1;

                retCnt +=cnt;
            }
            else
                retCnt = retCnt + N - cnt;

        }

        if(ret > retCnt)
            ret = retCnt;

        memcpy(mp, mp2, 20*20*4);
    }

    cout << ret;
}