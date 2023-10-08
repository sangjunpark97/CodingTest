#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int R, C, M;
int shark[10001][5];
int mp[100][100];
int tmp[100][100];
int ret;

void MoveShark()
{
    memset(tmp, 0, sizeof(tmp));

    for(int i = 1; i <= M; i++)
    {
        if(shark[i][4] == 0)
            continue;
        else
        {
            int dir = shark[i][3];
            int v = shark[i][2];
            int y = shark[i][0];
            int x = shark[i][1];
            int size = shark[i][4];

            if(dir == 1) //위
            {
                if(y - v < 0) // 왼끝 도달
                {
                    v = v - y;  //왼 끝 붙이기
                    
                    if((v / (R - 1)) % 2 == 0)
                    {
                        y = v %(R - 1);
                        shark[i][3] = 2;
                    }
                    else
                        y = (R - 1) - (v % (R - 1));
                }
                else
                {
                    y = y - v;
                }
            }
            else if(dir == 2) //down
            {
                int offset = (R - 1) - y;

                if(y + v >= R) // 아래 도달 0
                {
                    v = v - offset;

                    if((v / (R -1)) % 2 == 0)
                    {
                        y = R - 1 - v % (R - 1);
                        shark[i][3] = 1;
                    }
                    else
                        y = v % (R - 1);
                }
                else // 아래 도달 x
                {
                    y = y + v;
                }
            }
            else if(dir == 3) //right
            {
                int offset = (C - 1) - x; // 오른끝 붙이기

                if(v > (C - 1) - x) //오른끝 도달 x
                {
                    v = v - offset;

                    if((v / (C - 1)) % 2 == 0)
                    {
                        x = (C - 1) - (v % (C - 1));
                        shark[i][3] = 4;
                    }
                    else
                    {
                        x = (v % (C - 1));
                    }
                }
                else
                {
                    x = x + v;
                }
            }
            else if(dir == 4) //left
            {
                if(x - v < 0) // 왼끝 도달
                {
                    v = v - x;  //왼 끝 붙이기

                    if((v / (C - 1)) % 2 == 0)
                    {
                        x = v %(C - 1);
                        shark[i][3] = 3;
                    }
                    else
                        x = (C - 1) - (v % (C - 1));
                }
                else
                {
                    x = x - v;
                }
            }

            if(tmp[y][x]) //크기비교
            {
                if(shark[tmp[y][x]][4] < size) // 먹기
                {
                    shark[tmp[y][x]][4] = 0;
                    tmp[y][x] = i;
                }
                else //죽기
                    shark[i][4] = 0;
            }
            else
                tmp[y][x] = i;

            shark[i][0] = y;
            shark[i][1] = x;
        }
    }
}

int main()
{
    cin >> R >> C >> M;

    for(int i = 1; i <= M; i++)
    {
        int r, c;
        cin >> r >> c >> shark[i][2] >> shark[i][3] >> shark[i][4];
        shark[i][0] = r - 1;
        shark[i][1] = c - 1;
        mp[shark[i][0]][shark[i][1]] = i;
    }

    for(int x = 0; x < C; x++)
    {
        for(int y = 0; y < R; y++)
        {
            if(mp[y][x] != 0)
            {
                ret += shark[mp[y][x]][4];
                shark[mp[y][x]][4] = 0;
                mp[y][x] = 0;
                break;
            }
        }

        MoveShark();

        memcpy(mp, tmp, sizeof(tmp));
    }

    cout << ret;
}