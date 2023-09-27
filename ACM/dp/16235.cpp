#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mp[11][11];
int robot[11][11];
int death[11][11];
int dy[8] ={-1,-1,-1,1,1,1,0,0};
int dx[8] ={1,0,-1,1,0,-1,-1,1};
deque<pair<int,int>> v;

int main()
{
    fastio;
    int N, M, K;

    cin >> N >> M >> K;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            cin >>robot[y][x];
            mp[y][x] = 5;
        }
    }

    for(int i = 0; i < M; i++)
    {
        int y,x,z;

        cin >> y >> x >> z;

        int k = (y - 1) * N + (x - 1);

        v.push_back(pair<int,int>(z,k));
    }

    sort(v.begin(), v.end());

    for(int t = 0; t < K; t++)
    {
        deque<pair<int,int>> tmp;

        for(int i = 0; i < v.size(); i++)
        {
            int y = v[i].second / N;
            int x = v[i].second % N;
            int age = v[i].first;

            if(age == 0)
                continue;

            if(mp[y][x] < age)
                death[y][x] += age / 2;
            else
            {
                mp[y][x] -= age;
                age++;
                tmp.push_back(pair<int,int>(age, v[i].second));

                if(age % 5 == 0)
                {
                    for(int j = 0; j < 8; j++)
                    {
                        int ny = y + dy[j];
                        int nx = x + dx[j];

                        if(ny < 0 || nx < 0 || nx >= N || ny >= N)
                            continue;

                        tmp.push_front(pair<int,int>(1,ny * N + nx));
                    }
                }
            }
        }

        v = tmp;

        for(int y = 0; y < N; y++)
        {
            for(int x = 0; x < N; x++)
            {
                mp[y][x] += death[y][x] + robot[y][x]; 
                death[y][x] = 0;
            }
        }
    }

    int ret = 0;

    for(int i = 0; i < v.size(); i++)
    {
        if(v[i].first > 0)
            ret++;
    }

    cout << ret;
}