#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mp[501][501];

int main()
{
    fastio;

    int N, M;

    cin >> N >> M;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            cin >> mp[y][x];
        }
    }

    int ret = 0;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            for(int i = 0; i < 19; i++)
            {
                int sum = mp[y][x];

                if(i == 0)
                {
                    if(x + 3 >= M)
                        continue;
                    
                    sum+=mp[y][x + 1] + mp[y][x+2] +mp[y][x+3];
                }
                else if(i == 1)
                {
                    if(y + 3 >= N)
                        continue;
                    
                    sum += mp[y + 1][x] + mp[y + 2][x] + mp[y + 3][x];
                }
                else if(i == 2)
                {
                    if(x + 1 >= M || y + 1 >= N)
                        continue;

                    sum +=mp[y][x+1] +mp[y+1][x] + mp[y+1][x+1];
                }
                else if(i == 3)
                {
                    if(y + 2 >= N || x +1 >=M)
                        continue;
                    
                    sum+=mp[y+1][x] + mp[y+2][x] + mp[y+2][x+1];
                }
                else if(i == 4)
                {
                    if(y + 2 >= N || x - 1 < 0)
                        continue;
                    
                    sum += mp[y + 1][x] + mp[y + 2][x] + mp[y + 2][x - 1];
                }
                else if(i == 5)
                {
                    if(y + 2 >= N || x + 1 >= M)
                        continue;
                    
                    sum += mp[y][x+1] + mp[y+1][x] + mp[y+2][x];
                }
                else if(i == 6)
                {
                    if(y + 2 >= N || x+ 1 >=M)
                        continue;
                    
                    sum += mp[y][x+1] + mp[y + 1][x+1] + mp[y + 2][x+1];
                }
                else if(i == 7)
                {
                    if(y + 1 >= N || x - 2 < 0)
                        continue;
                    
                    sum+= mp[y+ 1][x - 2] + mp[y+ 1][x - 1] + mp[y +1][x];
                }
                else if(i == 8)
                {
                    if(y + 1 >= N || x + 2 >= M)
                        continue;

                    sum += mp[y+1][x] + mp[y+1][x+1] + mp[y+1][x+2];
                }
                else if(i == 9)
                {
                    if(y + 1 >= N || x + 2 >= M)
                        continue;
                    
                    sum+= mp[y][x+1] + mp[y][x+ 2] + mp[y + 1][x+2];
                }
                else if(i== 10)
                {
                    if(y + 1 >= N || x+ 2 >= M)
                        continue;
                    
                    sum+= mp[y][x+1] + mp[y][x+2] + mp[y+1][x];
                }
                else if(i == 11)
                {
                    if(y + 2 >= N || x + 1 >= M)
                        continue;
                    
                    sum+=mp[y+1][x]+mp[y+1][x + 1]+mp[y + 2][x+1];
                }
                else if(i == 12)
                {
                    if(y + 2 >= N ||  x - 1 < 0)
                        continue;
                    
                    sum+=mp[y + 1][x] + mp[y + 1][x-1] + mp[y + 2][x - 1];
                }
                else if(i == 13)
                {
                    if(y - 1 < 0 || x+ 2 >=M)
                        continue;
                    
                    sum += mp[y][x+1] + mp[y - 1][x+ 1] + mp[y - 1][x + 2];
                }
                else if(i == 14)
                {
                    if(y + 1 >= N || x + 2 >= M)
                        continue;
                    
                    sum += mp[y][x+ 1] + mp[y + 1][x+ 1] + mp[y+ 1][x+2];
                }
                else if(i == 15)
                {
                    if(x + 2 >= M || y - 1 < 0)
                        continue;
                    
                    sum+=mp[y][x+1] + mp[y][x+2] + mp[y - 1][x+1];
                }
                else if(i == 16)
                {
                    if(x + 1 >= M || y + 2 >= N)
                        continue;
                    
                    sum += mp[y+1][x] + mp[y + 2][x] + mp[y + 1][x+1];
                }
                else if(i == 17)
                {  
                    if(x + 2 >= M || y + 1 >= N)
                        continue;
                    
                    sum+=mp[y][x+1]+mp[y][x+2]+mp[y+1][x+1];
                }
                else if(i == 18)
                {
                    if(x -1 < 0 || y +2 >= N)
                        continue;
                    
                    sum+=mp[y+ 1][x] + mp[y + 2][x] + mp[y +1][x - 1];
                }


                ret = max(ret,sum);
            }
        }
    }

    cout << ret;
}