#include <bits/stdc++.h>
using namespace std;

int mp[10][10];
int visited[10][10];
int N;
int ret = 987654321;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

void go(int cnt)
{
    if(cnt == 3)
    {
        int g = 0;

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(visited[i][j])
                    g+=mp[i][j];
            }
        }

        if(g < ret)
        {
            ret = g;
        }
    }
    else
    {
        for(int y = 1; y < N - 1; y++)
        {
            for(int x = 1; x < N - 1; x++)
            {
                bool bCheck = true;

                if(visited[y][x])
                    bCheck = false;

                for(int i = 0; i < 4; i++)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if(visited[ny][nx])
                    {
                        bCheck = false;
                        break;
                    }
                }

                if(bCheck)
                {
                    visited[y][x] = 1;

                    for(int i = 0; i < 4; i++)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];

                        visited[ny][nx] = 1;
                    }

                    go(cnt+1);

                    visited[y][x] = 0;

                    for(int i = 0; i < 4; i++)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];

                        visited[ny][nx] = 0;
                    }
                }
            }
        }
    }
}


int main()
{
    cin >> N;

    for(int y = 0 ; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            cin >> mp[y][x];
        }
    }

    go(0);

    cout << ret;
}