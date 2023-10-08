#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mp[8][8];
int visited[8][8];
queue<pair<int,int>> que;
queue<pair<int,int>> queFor2;
int dy[4] = {-1,1,0,0};
int dx[4] = {0,0,-1,1};
int N, M;
int cnt;
int ret;

void BFS()
{
    while(que.size())
    {
        int y = que.front().first;
        int x = que.front().second;

        if(visited[y][x] == 0)
            visited[y][x] = 1;

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny >= N || nx >= M || ny < 0 || nx < 0 || visited[ny][nx] || mp[ny][nx] != 0)
                continue;
            
            visited[ny][nx] = visited[y][x] + 1;
            que.push(pair<int,int>(ny,nx));    
        }

        que.pop();
    }
}

int main()
{
    fastio;

    cin >> N >> M;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            cin >> mp[y][x];

            if(mp[y][x] == 2)
                queFor2.push(pair<int,int>(y,x));

            if(mp[y][x] == 0)
                cnt++;
        }
    }

    for(int idx0 = 0; idx0 < N * M; idx0++)
    {
        int y0 = idx0 / M;
        int x0 = idx0 % M;

        if(mp[y0][x0] == 0)
        {
            mp[y0][x0] = -1;

            for(int idx1 = idx0 + 1; idx1 < N * M; idx1++)
            {
                int y1 = idx1 / M;
                int x1 = idx1 % M;

                if(mp[y1][x1] == 0)
                {
                    mp[y1][x1] = -1;

                    for(int idx2 = idx1 + 1; idx2 < N * M; idx2++)
                    {
                        int y2 = idx2 / M;
                        int x2 = idx2 % M;

                        if(mp[y2][x2] == 0)
                        {
                            int res = cnt;

                            mp[y2][x2] = -1;

                            memset(visited, 0, sizeof(visited));

                            que = queFor2;

                            BFS();

                            for(int y = 0; y < N; y++)
                            {
                                for(int x = 0; x < M; x++)
                                {
                                    if(visited[y][x] != 0 && mp[y][x] == 0)
                                        res--;
                                }
                            }

                            res = res - 3;

                            ret = max(res, ret);

                            mp[y2][x2] = 0;
                        }
                    }

                    mp[y1][x1] = 0;
                }
            }

            mp[y0][x0] = 0;
        }
    }

    cout << ret;
}