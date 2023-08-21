#include <bits/stdc++.h>
using namespace std;

const int Dx[4] = {0,0,-1,1};
const int Dy[4] = {-1,1,0,0};
int mp[100][100];
int visited[100][100];

int M, N;

void DFS(int y, int x, int k)
{
   if(visited[y][x])
      return;
   else if(mp[y][x] == 1)
   {
      visited[y][x] = 1;

      for(int i = 0; i < 4; ++i)
      {
         int u = y + Dy[i];
         int v = x + Dx[i];

         if(u < 0 || v <0 || u >= M || v >= N)
            continue;

         DFS(u, v, k);
      }
   }
}

int main()
{
    int M, N;

    cin >> M >> N;

    for(int y = 0; y < M; ++y)
    {
        for(int x = 0; x < N; ++x)
        {
           mp[y][x] = 0;
        }
    }

    for(int y = 0; y < M; ++y)
    {
        for(int x = 0; x < N; ++x)
        {
            visited[y][x] = 0;
        }
    }

    int K = 0;

    cin >> K;

    for(int i = 0; i < K; ++i)
    {
        int x1, y1, x2, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        for(int y = y1; y < y2; ++y)
        {
            for(int x = x1; x < x2; ++x)
            {
                mp[y][x] = 1;
            }
        }
    }

    vector<int> ret;

    for(int y = 0; y < M; ++y)
    {
        for(int x = 0; x < N; ++x)
        {
           if(visited[y][x] == 0 && mp[y][x] == 1)
            {
                int k = 0;
                DFS(y,x, k);
                ret.push_back(k);
            }
        }
    }

    sort(ret.begin(), ret.end());

    cout << ret.size() << endl;
    
    for(auto i : ret)
        cout << i << " ";
}