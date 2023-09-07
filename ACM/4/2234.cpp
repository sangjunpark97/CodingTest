#include <bits/stdc++.h>
using namespace std;

int mp[50][50];
int visited[50][50];
int s;
int dy[4] = {0,-1,0,1};
int N, M;
int dx[4] = {-1,0,1,0};

void DFS(int y, int x, int num)
{
    s++;

    for(int i = 0; i < 4; i++)
    {
        if((mp[y][x] & (1 << i)) == 0)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny < 0 || nx <0 || ny >=N || nx >= M || visited[ny][nx])
                continue;
            
            visited[ny][nx] = num;
            DFS(ny, nx, num);
        }
    }
}

int main()
{
    vector<int> vctSize;

    cin >> M >> N;

    for(int y = 0; y < N; y++)
    {
        for(int x =0; x < M; x++)
        {
            cin >> mp[y][x];
        }
    }

    int cnt = 0;

    for(int y = 0; y < N; y++)
    {
        for(int x =0; x < M; x++)
        {
            s = 0;

            if(!visited[y][x])
            {
                cnt++;
                visited[y][x] = cnt;
                DFS(y,x, cnt);
                vctSize.push_back(s);
            }
        }
    }

    int ret = 0;

    for(int y = 0; y < N; y++)
    {
        for(int x =0; x < M; x++)
        {
            for(int i = 0; i < 4; i++)
            {
                int ny = y +dy[i];
                int nx = x+dx[i];

                if(ny < 0 || nx <0 || ny >=N || nx >= M)
                    continue;

                if(visited[y][x] != visited[ny][nx])
                {
                    ret = max(ret, vctSize[visited[y][x] - 1] + vctSize[visited[ny][nx] - 1]);
                }
            }
        }
    }

    sort(vctSize.begin(),vctSize.end());

    cout << cnt <<"\n";
    cout << vctSize.back() <<"\n";
    cout << ret;
}