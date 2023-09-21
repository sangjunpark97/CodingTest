#include <bits/stdc++.h>

using namespace std;

int mp[51][51];
int temp[51][51];
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int main()
{
    int N, M, T;

    cin >> N >> M >> T;

    for(int i = 1; i <= N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> mp[i][j];
        }
    }

    for(int i = 0; i < T; i++)
    {
        int x, d, k;

        cin >> x >> d >> k;

        for(int l = x; l <= N; l += x)
        {
            if(d == 0)
            {
                memcpy(temp, mp, sizeof(mp));

                for(int n = 0; n < M; n++)
                    temp[l][(n + k) % M] = mp[l][n];

                memcpy(mp, temp, sizeof(temp));
            }
            else if(d == 1)
            {
                memcpy(temp, mp, sizeof(mp));

                for(int n = 0; n < M; n++)
                    temp[l][(n + (M - k)) % M] = mp[l][n];

                memcpy(mp, temp, sizeof(temp));
            }
        }

        bool bCheck = false;

        memcpy(temp, mp, sizeof(mp));

        for(int y = 1; y <= N; y++)
        {
            for(int x = 0; x < M; x++)
            {
                for(int i = 0; i < 4; i++)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if(ny == -1 || ny == N + 1)
                        continue;

                    if(nx == -1)
                        nx = M - 1;
                    else if(nx == M)
                        nx = 0;

                    if(mp[y][x] == mp[ny][nx])
                    {
                        if(mp[y][x] == 0)
                            continue;

                        temp[y][x] = temp[ny][nx] = 0;
                        bCheck = true;
                    }
                }
            }
        }

        memcpy(mp, temp, sizeof(temp));

        if(bCheck == false)
        {
            double sum = 0;
            double cnt = 0;

            for(int y = 1; y <= N; y++)
            {
                for(int x = 0; x < M; x++)
                {
                    if(mp[y][x] == 0)
                        continue;
                    
                    sum+=mp[y][x];
                    cnt++;
                }
            }

            double avg = sum /cnt;

            for(int y = 1; y <= N; y++)
            {
                for(int x = 0; x < M; x++)
                {
                    if(mp[y][x] == 0)
                        continue;
                    
                    if((double)mp[y][x] < avg)
                        mp[y][x]++;
                    else if((double)mp[y][x] > avg)
                        mp[y][x]--;
                }
            }
        }

    }

    int ret = 0;

    for(int y = 1; y <= N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            if(mp[y][x] == 0)
                continue;
            
            ret+=mp[y][x];
        }
    }

    cout << ret;
}