#include <bits/stdc++.h>

using namespace std;

int mp[50][50];
int mp2[50][50];
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
vector<pair<int, int>> a;

int main()
{
    int R, C, T;

    cin >> R >> C >> T;

    for(int y = 0; y < R; y++)
    {
        for(int x = 0; x < C; x++)
        {
            cin >> mp[y][x];
            
            if(mp[y][x] == -1)
            {
                a.push_back(pair<int, int>(y,x));
            }
        }
    }

    while(T--)
    {
        for(int y = 0; y < R; y++)
        {
            for(int x = 0; x < C; x++)
            {
                if(mp[y][x] > 0)
                {
                    int m = mp[y][x] / 5;
                    int cnt = 0;

                    for(int i = 0; i < 4; i++)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];

                        if(ny < 0 || nx < 0 || nx >=C || ny >= R || mp[ny][nx] == -1)
                            continue;

                        cnt++;
                        mp2[ny][nx] += m;
                    }

                    mp2[y][x] -= m * cnt;
                }
            }
        }

        for(int y = 0; y < R; y++)
        {
            for(int x = 0; x < C; x++)
                mp[y][x] += mp2[y][x];
        }

        memset(mp2, 0, sizeof(mp2));

        int y0 = a[0].first;
        int x0 = a[0].second;

        for(int y = y0 - 1; y > 0; y--)
            mp[y][0] = mp[y - 1][0];

        for(int x = 0; x < C - 1; x++)
            mp[0][x] = mp[0][x + 1];

        for(int y = 0; y < y0; y++)
            mp[y][C-1] = mp[y + 1][C-1];

        for(int x = C - 1; x >= x0 + 2; x--)
            mp[y0][x] = mp[y0][x - 1];
        
        mp[y0][x0 + 1] = 0;


        int y1 = a[1].first;
        int x1 = a[1].second;

        for(int y = y1 + 1; y < R - 1; y++)
            mp[y][0] = mp[y + 1][0];

        for(int x = 0; x < C - 1; x++)
            mp[R - 1][x] = mp[R - 1][x + 1];

        for(int y = R - 1; y > y1; y--)
            mp[y][C-1] = mp[y - 1][C-1];

        for(int x = C - 1; x >= 2; x--)
            mp[y1][x] = mp[y1][x - 1];
        
        mp[y1][x1 + 1] = 0;
    }

    int ret = 0;

    for(int y = 0; y < R; y++)
    {
        for(int x= 0; x < C; x++)
        {
            if(mp[y][x]> 0 )
                ret+=mp[y][x];
        }
    }

    cout << ret;
}