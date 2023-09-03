#include <bits/stdc++.h>
using namespace std;

int mp[1500][1500];
int visitedL[1500][1500];
int visited[1500][1500];
queue<pair<int,int>> que;
queue<pair<int,int>> queL;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main()
{
    int N, M;
    vector<pair<int,int>> vctL;

    cin >> N >> M;

    for(int i = 0; i< N; ++i)
    {
        string s;
        
        cin >> s;

        for(int j = 0; j < s.length(); j++)
        {
            if(s[j] == 'L')
                vctL.push_back(pair<int, int>(i,j));
            else if(s[j] == 'X')
                mp[i][j] = 1;
        }
    }

    int ret = 0;

    queL.push(pair<int, int>(vctL[0].first, vctL[0].second));

    while(true)
    {
        queue<pair<int,int>> tmpL;

        while(queL.size())
        {
            int y = queL.front().first;
            int x = queL.front().second;

            queL.pop();
            
            for(int i = 0; i< 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny < 0 || nx < 0 || ny >= N || nx >= M || visitedL[ny][nx])
                    continue;

                visitedL[ny][nx] = 1;

                if(mp[ny][nx] == 1)
                {
                    tmpL.push(pair<int, int>(ny,nx));
                }
                else if(ny == vctL[1].first && nx == vctL[1].second)
                {
                    cout << ret;
                    return 0;
                }
                else
                    queL.push(pair<int, int>(ny,nx));
            }
        }

        queL = tmpL;

        ret++;

        queue<pair<int,int>> tmp;

        if(ret == 1)
        {
            for(int y = 0; y < N; ++y)
            {
                for(int x = 0; x < M; ++x)
                {
                    if(visited[y][x] == 0 && mp[y][x] == 0)
                    {
                        que.push(pair<int,int>(y,x));

                        while(que.size())
                        {
                            int y0 = que.front().first;
                            int x0 = que.front().second;

                            que.pop();

                            for(int i = 0; i< 4; i++)
                            {
                                int ny = y0 + dy[i];
                                int nx = x0 + dx[i];

                                if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])
                                    continue;

                                visited[ny][nx] = ret;

                                if(mp[ny][nx] != 0)
                                {
                                    mp[ny][nx] = 0;
                                    tmp.push(pair<int,int>(ny,nx));
                                }
                                else
                                    que.push(pair<int,int>(ny,nx));
                            }
                        }
                    }
                }
            }

            que = tmp;
        }
        else
        {
            while(que.size())
            {
                int y0 = que.front().first;
                int x0 = que.front().second;

                que.pop();

                for(int i = 0; i< 4; i++)
                {
                    int ny = y0 + dy[i];
                    int nx = x0 + dx[i];

                    if(ny < 0 || nx < 0 || ny >= N || nx >= M || visited[ny][nx])
                        continue;

                        visited[ny][nx] = ret;

                    if(mp[ny][nx] != 0)
                    {
                        mp[ny][nx] = 0;
                        tmp.push(pair<int,int>(ny,nx));
                    }
                    else
                        que.push(pair<int,int>(ny,nx));
                }
            }

            que = tmp;
        }
    }
}