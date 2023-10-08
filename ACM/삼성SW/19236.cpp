#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mp[4][4][2];
int fish[17][3];
int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};


int go(int y, int x)
{
    int ret = 0;

    // EAT
    ret += mp[y][x][0];
    fish[mp[y][x][0]][2] = 0;
    mp[y][x][0] = 0;

    for(int i = 1; i <= 16; i++)
    {
        int r = fish[i][0];
        int c = fish[i][1];

        if(fish[i][2] != 0)
        {
            // FISH MOVE
            int ny = fish[i][0] + dy[fish[i][2]];
            int nx = fish[i][1] + dx[fish[i][2]];

            while(ny < 0 || nx < 0 || ny >= 4 || nx >= 4 || (ny == y && nx == x))
            {
                fish[i][2]++;

                if(fish[i][2] == 9)
                    fish[i][2] = 1;
                    
                ny = fish[i][0] + dy[fish[i][2]];
                nx = fish[i][1] + dx[fish[i][2]];
                mp[r][c][1] = fish[i][2];
            }

            if(mp[ny][nx][0] != 0)
            {
                int swapIdx = mp[ny][nx][0];
                int swapDir = mp[ny][nx][1];

                mp[ny][nx][0] = mp[r][c][0];
                mp[ny][nx][1] = mp[r][c][1];

                mp[r][c][0] = swapIdx;
                mp[r][c][1] = swapDir;

                fish[swapIdx][0] = r;
                fish[swapIdx][1] = c;
            }
            else
            {
                mp[ny][nx][0] = mp[r][c][0];
                mp[ny][nx][1] = mp[r][c][1];
                mp[r][c][0] = 0;
            }

            fish[i][0] = ny;
            fish[i][1] = nx;
        }
    }


    int tmp = 0;
    int dir = mp[y][x][1];

    while(true)
    {
        int ny = y + dy[dir];
        int nx = x + dx[dir];


        if(ny < 0 || nx < 0 || nx >= 4 || ny >= 4)
            break;

        if(mp[ny][nx][0] != 0)
        {
            int pm[4][4][2];
            int hsif[17][3];
            memcpy(pm, mp, sizeof(pm));
            memcpy(hsif, fish, sizeof(hsif));

            tmp = max(tmp,go(ny,nx));

            memcpy(mp, pm, sizeof(pm));
            memcpy(fish, hsif, sizeof(hsif));
        }

        y = ny;
        x = nx;
    }

    return ret + tmp;
}

int main()
{

    for(int y = 0; y < 4; y++)
    {
        for(int x = 0; x < 4; x++)
        {
            int a, b;

            cin >> a >> b;

            fish[a][0] = y;
            fish[a][1] = x;
            fish[a][2] = b;

            mp[y][x][0] = a;
            mp[y][x][1] = b;
        }
    }


    cout << go(0,0);
}