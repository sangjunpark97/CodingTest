#include <bits/stdc++.h>
using namespace std;

char mp[20][20];
int visited[20][20];
int score[20][20];
int max0;
vector<char> vctChar;
int N, M;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ret = 0;

void DFS(int y, int x, string vct)
{
    if(ret < vct.length())
        ret = vct.length();
    
    if(ret == max0)
        return;

    for(int i = 0; i< 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])
            continue;

        if(vct.find(mp[ny][nx]) == string::npos)
        {
            visited[ny][nx] = 1;
            vct.push_back(mp[ny][nx]);
            DFS(ny,nx,vct);
            vct.pop_back();
            visited[ny][nx] = 0;
        }
    }
}

int main()
{
    cin >> N >> M;
    string sA;

    for(int y = 0; y < N; ++y)
    {
        string s;

        cin >> s;

        for(int x = 0; x < M; ++x)
        {
            mp[y][x] = s[x];
            
            if(sA.find(mp[y][x]) == string::npos)
                sA.push_back(s[x]);
        }
    }

    max0 = sA.length();
    string vct;

    vct.push_back(mp[0][0]);

    DFS(0, 0, vct);

    cout << ret;
}