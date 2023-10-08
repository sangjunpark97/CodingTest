#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mp[20][20];
int visited[20][20];
int N;
int dy[4] = {1, 0, 0, -1};
int dx[4] = {0, -1, 1, 0};
pair<int, int> shark;
queue<pair<int,int>> que;

int main()
{
    /*
    N x N 한 칸에 상어 1
    상어와 물고기 같은 크기 (자연수)
    가장 처음 아기상어 크기 2
    1초에 상하좌우 이동
    자기보다 큰 물고기 이동 x
    크기가 같으면 먹을 수 없지만 이동 가능
    도움 요청 시 종료

    물고기 1마리 -> 먹으러감
    물고기 1이상 -> 가장 가까운 물고기
    */

    cin >> N;
    
    int nowY, nowX;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            cin >> mp[y][x];

            if(mp[y][x] == 9)
            {
                nowY = y;
                nowX = x;
                mp[y][x] = 0;
                visited[y][x] = 1;
            }
        }
    }

    shark.first = 2;
    shark.second = 0;

    int ret = 0;

    while(true)
    {
        que.push(make_pair(nowY, nowX));

        vector<pair<int,int>> v;

        while(que.size())
        {
            int y = que.front().first;
            int x = que.front().second;

            for(int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if(ny >= N || nx >= N || ny < 0 || nx <0 || visited[ny][nx])
                    continue;
                
                if(shark.first < mp[ny][nx])
                {
                    continue;
                }
                else if(shark.first == mp[ny][nx])
                {
                    que.push(make_pair(ny,nx));
                    visited[ny][nx] = visited[y][x] + 1;
                }
                else if(mp[ny][nx] != 0)
                {
                    v.push_back(make_pair(visited[y][x], ny * N + nx));
                }
                else if(mp[ny][nx] == 0)
                {
                    visited[ny][nx] = visited[y][x] + 1;
                    que.push(make_pair(ny,nx));
                }
            }
            
            if(que.size())
                que.pop();
        }

        if(v.size())
        {
            sort(v.begin(), v.end());
            nowY = v[0].second / N;
            nowX = v[0].second % N;
            mp[nowY][nowX] = 0;
            shark.second++;

            if(shark.first == shark.second)
            {
                shark.first++;
                shark.second = 0;
            }

            ret += v[0].first;

            while(!que.empty()) que.pop();

            memset(visited, 0, sizeof(visited));
            visited[nowY][nowX] = 1;
        }
        else
            break;
    }

    cout << ret;
}