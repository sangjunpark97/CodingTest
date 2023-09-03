#include <bits/stdc++.h>
using namespace std;

int mp[300][300];
int visited[300][300];
queue<pair<int,int>> que;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
    int N, M;

    cin >> N >> M;

    int sx, sy, y1,x1;

    cin >> sy >> sx >> y1 >> x1;

    sy--;
    sx--;
    y1--;
    x1--;

    for(int i = 0; i< N; ++i)
    {
        string s;
        
        cin >> s;

        for(int j = 0; j < s.length(); j++)
        {
            if(s[j] == '#')
                mp[i][j] = -1;
            else if(s[j] == '1')
                mp[i][j] = 1;
        }
    }

    int ret = 0;

    while(mp[y1][x1] != 0)
    {
        queue<pair<int,int>> queN;

        que.push(pair<int, int>(sy, sx));

        ret++;

        while(que.size())
        {
            int y = que.front().first;
            int x = que.front().second;

            for(int i = 0; i<4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny <0 || nx < 0 || nx >= M || ny >= N || visited[ny][nx])
                    continue; 

                visited[ny][nx] = ret;

                if(mp[ny][nx]!=0)
                {
                    mp[ny][nx] = 0;
                    queN.push(pair<int, int>(ny,nx));
                }
                else
                    que.push(pair<int, int>(ny,nx));
            }
            
            que.pop();
        }

        que = queN;
    }

    cout << visited[y1][x1];
}