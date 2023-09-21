#include <bits/stdc++.h>

using namespace std;

int mp[10][10];
int number[8];
pair<int,int> pos[8];
int num;
int N, M;
int ret = 987654321;


void go(int cnt)
{
    if(cnt == num)
    {
        int sum = 0;

        for(int y = 0 ; y < N; y++)
        {
            for(int x = 0; x< M; x++)
            {
                if(mp[y][x] == 0)
                    sum++;
            }
        }

        ret = min(ret, sum);
    }
    else
    {
        int k = number[cnt];
        int tmp[10][10];

        memcpy(tmp, mp, sizeof(mp));

        if(k == 1)
        {
            //1
            for(int x = pos[cnt].second + 1; x < M; x++)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }

            go(cnt + 1);

            memcpy(mp, tmp, sizeof(tmp));
            //2
            for(int y = pos[cnt].first + 1; y < N; y++)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            go(cnt + 1);
            memcpy(mp, tmp, sizeof(tmp));
            //4

            for(int x = pos[cnt].second - 1; x >= 0; x--)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }

            go(cnt + 1);
            
            memcpy(mp, tmp, sizeof(tmp));

            //8
            for(int y = pos[cnt].first - 1; y >= 0; y--)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            go(cnt + 1);
            
            memcpy(mp, tmp, sizeof(tmp));
        }
        else if(k == 2)
        {
            for(int x = pos[cnt].second + 1; x < M; x++)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }


            for(int x = pos[cnt].second - 1; x >= 0; x--)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }

            go(cnt + 1);

            memcpy(mp, tmp, sizeof(tmp));


            for(int y = pos[cnt].first - 1; y >= 0; y--)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            for(int y = pos[cnt].first + 1; y < N; y++)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            go(cnt + 1);
            
            memcpy(mp, tmp, sizeof(tmp));
        }
        else if(k == 3)
        {

            //1
            for(int x = pos[cnt].second + 1; x < M; x++)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }
            
            //2
            for(int y = pos[cnt].first + 1; y < N; y++)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            go(cnt + 1);
            
            memcpy(mp, tmp, sizeof(tmp));

            //2
            for(int y = pos[cnt].first + 1; y < N; y++)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            //4

            for(int x = pos[cnt].second - 1; x >= 0; x--)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }

            go(cnt + 1);
            
            memcpy(mp, tmp, sizeof(tmp));


            //4

            for(int x = pos[cnt].second - 1; x >= 0; x--)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }

            //8
            for(int y = pos[cnt].first - 1; y >= 0; y--)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            go(cnt + 1);
            
            memcpy(mp, tmp, sizeof(tmp));


            //1
            for(int x = pos[cnt].second + 1; x < M; x++)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }

            //8
            for(int y = pos[cnt].first - 1; y >= 0; y--)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            go(cnt + 1);
            
            memcpy(mp, tmp, sizeof(tmp));
        }
        else if(k == 4)
        {
            //2
            for(int y = pos[cnt].first + 1; y < N; y++)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            //4

            for(int x = pos[cnt].second - 1; x >= 0; x--)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }

            //8
            for(int y = pos[cnt].first - 1; y >= 0; y--)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            go(cnt + 1);
            
            memcpy(mp, tmp, sizeof(tmp));

            //1
            for(int x = pos[cnt].second + 1; x < M; x++)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }

            //4

            for(int x = pos[cnt].second - 1; x >= 0; x--)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }

            //8
            for(int y = pos[cnt].first - 1; y >= 0; y--)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            go(cnt + 1);
            
            memcpy(mp, tmp, sizeof(tmp));


            //1
            for(int x = pos[cnt].second + 1; x < M; x++)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }

            //2
            for(int y = pos[cnt].first + 1; y < N; y++)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            //8
            for(int y = pos[cnt].first - 1; y >= 0; y--)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            go(cnt + 1);
            
            memcpy(mp, tmp, sizeof(tmp));


            //1
            for(int x = pos[cnt].second + 1; x < M; x++)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }

            //2
            for(int y = pos[cnt].first + 1; y < N; y++)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            //4

            for(int x = pos[cnt].second - 1; x >= 0; x--)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }

            go(cnt + 1);
            
            memcpy(mp, tmp, sizeof(tmp));
        }
        else if(k == 5)
        {
            //1
            for(int x = pos[cnt].second + 1; x < M; x++)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }
            
            //2
            for(int y = pos[cnt].first + 1; y < N; y++)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            //4

            for(int x = pos[cnt].second - 1; x >= 0; x--)
            {
                if(mp[pos[cnt].first][x] == 6)
                    break;
                else if(mp[pos[cnt].first][x] == 0)
                    mp[pos[cnt].first][x] = -1;
            }

            //8
            for(int y = pos[cnt].first - 1; y >= 0; y--)
            {
                if(mp[y][pos[cnt].second] == 6)
                    break;
                else if(mp[y][pos[cnt].second] == 0)
                    mp[y][pos[cnt].second] = -1;
            }

            go(cnt + 1);
            
            memcpy(mp, tmp, sizeof(tmp));
        }
    }
}

int main()
{
    cin >> N >> M;

    for(int y = 0 ; y < N; y++)
    {
        for(int x = 0; x< M; x++)
        {
            cin >> mp[y][x];

            if(mp[y][x] != 0 && mp[y][x] != 6)
            {
                number[num] = mp[y][x];
                pos[num].first = y;
                pos[num].second = x;
                num++;
            }
        }
    }

    go(0);

    cout << ret;
}