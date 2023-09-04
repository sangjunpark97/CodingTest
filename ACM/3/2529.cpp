#include <bits/stdc++.h>
using namespace std;

char mp[20][20];
int visited[20][20];
int Alpha[26];
vector<char> vctChar;
int N, M;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ret = 0;

void DFS(int y, int x, int cnt)
{
    if(cnt > ret)
        ret = cnt;

    for(int i = 0; i< 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])
            continue;

        int next = mp[ny][nx] - 'A';

        if(Alpha[next] == 0)
        {
            Alpha[next] = 1;
            visited[ny][nx] = 1;
            DFS(ny,nx, cnt+1);
            Alpha[next] = 0;
            visited[ny][nx] = 0;
        }
    }
}

int main()
{

    cin >> N >> M;

    for(int y = 0; y < N; ++y)
    {
        string s;

        cin >> s;

        for(int x = 0; x < M; ++x)
            mp[y][x] = s[x];
    }

    string vct;

    vct.push_back(mp[0][0]);
    Alpha[mp[0][0] - 'A'] = 1;
    DFS(0, 0, 1);

    cout << ret;
}