#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mp[51][51];
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};

int main()
{
    int N, M;

    cin >> N >> M;

    int y, x, dir;

    cin >> y >> x >> dir;

    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            cin >> mp[r][c];
        }
    }

    int ret = 0;


    while(true)
    {
        if(mp[y][x] == 0)
        {
            mp[y][x] = -1;
            ret++;
        }

        bool bChungso = true;

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx < 0 || ny >= N || nx >= M || mp[ny][nx])
                continue;

            bChungso = false;
            break;
        }

        while(!bChungso)
        {
            dir = (dir + 3) % 4;
            
            int ny = y;
            int nx = x;

            if(dir == 0)
            {
                ny = y - 1;
                nx = x;
            }
            else if(dir == 1)
            {
                ny = y;
                nx = x + 1;
            }
            else if(dir == 2)
            {
                ny = y + 1;
                nx = x;
            }
            else if(dir == 3)
            {
                ny = y;
                nx = x - 1;
            }

            if(ny < 0 || nx < 0 || ny >= N || nx >= M || mp[ny][nx])
                continue;
            else
            {
                y = ny; x = nx;
                break;
            }
        }

        if(bChungso)
        {
            int ny = y;
            int nx = x;

            if(dir == 2)
            {
                ny = y - 1;
                nx = x;
            }
            else if(dir == 3)
            {
                ny = y;
                nx = x + 1;
            }
            else if(dir == 0)
            {
                ny = y + 1;
                nx = x;
            }
            else if(dir == 1)
            {
                ny = y;
                nx = x - 1;
            }

            if(ny < 0 || nx < 0 || ny >= N || nx >= M || mp[ny][nx] == 1)
                break;
            else
            {
                y = ny;
                x = nx;
                continue;
            }
        }
    }

    cout << ret;
}