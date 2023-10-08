#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mp[50][50];
int visited2[50][50];
int visited[50][50];
int N, M;
int dy[4] = {0,0,-1,1};
int dx[4] = {-1,1,0,0};
vector<pair<int,int>> virus;
queue<pair<int,int>> que;

bool DFS(int y, int x)
{
    bool ret = true;

    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny >= N || nx >= N || ny < 0 || nx < 0 || visited2[ny][nx] || visited[ny][nx] || mp[ny][nx] == 1)
            continue;

        visited2[ny][nx] = 1;

        ret &= DFS(ny, nx) && (mp[ny][nx] == 2);
    }
    
    return ret;
}

int BFS()
{
    int ret = 0;

    while(que.size())
    {
        int y = que.front().first;
        int x = que.front().second;

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(ny >= N || nx >= N || ny < 0 || nx < 0 || visited[ny][nx] || mp[ny][nx] == 1)
                continue;

            if(mp[ny][nx] == 2)
            {
                memset(visited2, 0, sizeof(visited2));
                
                if(DFS(ny,nx) == true)
                    visited[ny][nx] = visited[y][x];
                else
                    visited[ny][nx] = visited[y][x] + 1;
            }
            else
                visited[ny][nx] = visited[y][x] + 1;

            ret = max(ret,visited[ny][nx]);
            que.push(pair<int,int>(ny,nx));
        }

        que.pop();
    }

    return ret;
}

int main()
{
    cin >> N >> M;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            cin >> mp[y][x];
            
            if(mp[y][x] == 2)
                virus.push_back(pair<int,int>(y,x));
        }
    }

    bool bCheckError =true;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            if(mp[y][x] == 0 && visited[y][x] == 0)
            {
                bCheckError = false;
            }
        }
    }

    if(bCheckError)
    {
        cout << "0";
        return 0;
    }


    vector<int> permut;

    permut.resize(virus.size() - M, 0);

    for(int i = 0; i < M; i++)
        permut.push_back(1);
    
    int ret = 2000000000;

    do
    {
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < permut.size(); i++)
        {
            if(permut[i] == 1)
            {
                que.push(virus[i]);
                visited[virus[i].first][virus[i].second] = 1;
            }
        }

        bool bCheck = true;

        int a = BFS();

        for(int y = 0; y < N; y++)
        {
            for(int x = 0; x < N; x++)
            {
                if(mp[y][x] == 0 && visited[y][x] == 0)
                {
                    bCheck = false;
                    break;
                }
            }
        }
        
        if(bCheck)
            ret = min(ret, a);
    } while (next_permutation(permut.begin(), permut.end()));
    
    if(ret == 2000000000)
        cout << "-1";
    else if(ret == 0)
        cout << ret;
    else
        cout << ret - 1;
}