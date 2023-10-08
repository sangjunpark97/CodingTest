#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mp[20][20];
int jusawi[6];
int tmp[6];


int main()
{
    fastio;
    int N, M, y, x, K;

    cin >> N >> M >> y >> x >> K;

    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < M; c++)
        {
            cin >> mp[r][c];
        }
    }

    for(int i = 0; i < K; i++)
    {
        int dir;

        cin >> dir;

        if(dir == 1)
        {
            if(x + 1 == M)
                continue;

            tmp[0] = jusawi[0];
            tmp[1] = jusawi[4];
            tmp[2] = jusawi[2];
            tmp[3] = jusawi[5];
            tmp[4] = jusawi[3];
            tmp[5] = jusawi[1];

            memcpy(jusawi,tmp, sizeof(tmp));

            if(mp[y][x + 1] != 0)
            {
                jusawi[3] = mp[y][x + 1];
                mp[y][x+1] = 0;
            }
            else
                mp[y][x + 1] = jusawi[3];
            
            x = x+1;
            cout << jusawi[1] << " ";
        }
        if(dir == 2)
        {
            if(x - 1 < 0)
                
                continue;
                
            tmp[0] = jusawi[0];
            tmp[1] = jusawi[5];
            tmp[2] = jusawi[2];
            tmp[3] = jusawi[4];
            tmp[4] = jusawi[1];
            tmp[5] = jusawi[3];

            memcpy(jusawi,tmp, sizeof(tmp));

            if(mp[y][x - 1] != 0)
            {
                jusawi[3] = mp[y][x - 1];
                mp[y][x-1] = 0;
            }
            else
                mp[y][x - 1] = jusawi[3];
            
            x = x-1;
            cout << jusawi[1] << " ";
        }
        if(dir == 3)
        {
            if(y - 1 < 0)
                continue;

            tmp[0] = jusawi[1];
            tmp[1] = jusawi[2];
            tmp[2] = jusawi[3];
            tmp[3] = jusawi[0];
            tmp[4] = jusawi[4];
            tmp[5] = jusawi[5];

            memcpy(jusawi,tmp, sizeof(tmp));

            if(mp[y - 1][x] != 0)
            {
                jusawi[3] = mp[y - 1][x];
                mp[y-1][x] = 0;
            }
            else
                mp[y - 1][x] = jusawi[3];
            
            y = y - 1;
            cout << jusawi[1] << " ";
        }
        if(dir == 4)
        {
            if(y + 1 == N)
                continue;

            tmp[0] = jusawi[3];
            tmp[1] = jusawi[0];
            tmp[2] = jusawi[1];
            tmp[3] = jusawi[2];
            tmp[4] = jusawi[4];
            tmp[5] = jusawi[5];

            memcpy(jusawi,tmp, sizeof(tmp));

            if(mp[y + 1][x] != 0)
            {
                jusawi[3] = mp[y + 1][x];
                mp[y+1][x] = 0;
            }
            else
                mp[y + 1][x] = jusawi[3];
            
            y = y + 1;
            cout << jusawi[1] << " ";
        }
    }
}