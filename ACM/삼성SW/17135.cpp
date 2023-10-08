#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mp[16][15];
int org[16][15];
int tmp[16][15];
int visited[16][15];
int N, M, D;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<pair<int,int>> que;

bool cmp(pair<int, int> &a, pair<int,int> &b)
{
    if(a.first < b.first)
        return true;
    else if(a.first == b.first)
    {
        return a.second % M < b.second % M;
    }
    else
        return false;
}

int main()
{
    cin >> N >> M >> D;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            cin >> org[y][x];
            
            mp[y][x] = org[y][x];
        }
    }

    vector<int> permut;

    permut.resize(M - 3, 0);

    for(int i = 0; i < 3; i++)
        permut.push_back(1);

    int ret = -1;
    
    do
    {
        memcpy(mp, org, sizeof(mp));

        int cnt = 0;

        for(int l = 0; l < N; l++)
        {
            if(l != 0)
            {
                memcpy(tmp, mp, sizeof(mp));
                memset(mp, 0, sizeof(mp));

                for(int y = 1; y < N; y++)
                {
                    for(int x = 0; x < M; x++)
                    {
                        mp[y][x] = tmp[y - 1][x];
                    }
                }
            }
            
            vector<int> archor;

            for(int i = 0; i < permut.size(); i++)
            {
                if(permut[i] == 1)
                    archor.push_back(i);
            }

            vector<pair<int,int>> death;

            for(auto a : archor)
            {
                vector<pair<int, int>> candi;

                memset(visited, 0, sizeof(visited));

                visited[N][a] = 1;

                que.push(make_pair(N, a));

                while(que.size())
                {
                    int y = que.front().first;
                    int x = que.front().second;

                    for(int i = 0; i < 4; i++)
                    {
                        int ny = y + dy[i];
                        int nx = x + dx[i];

                        if(ny >= N || nx >=M || ny < 0 || nx < 0 || visited[ny][nx])
                        {
                            continue;
                        }
                        
                        if(visited[y][x] <= D)
                        {
                            if(mp[ny][nx] == 1)
                                candi.push_back(make_pair(visited[y][x], ny * M + nx));
                                
                            visited[ny][nx] = visited[y][x] + 1;
                            que.push(make_pair(ny,nx));
                        }
                    }
                    
                    que.pop();
                }

                sort(candi.begin(), candi.end(), cmp);

                if(candi.size())
                    death.push_back(make_pair(candi[0].second / M, candi[0].second % M));
            }

            for(auto d : death)
            {
                if(mp[d.first][d.second] == 1)
                {
                    cnt++;
                    mp[d.first][d.second] = 0;
                }
            }
        }

        ret = max(ret, cnt);
    } while (next_permutation(permut.begin(), permut.end()));
    
    cout << ret;
}