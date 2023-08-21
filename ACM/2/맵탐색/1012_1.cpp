#include <bits/stdc++.h>
using namespace std;

const int Dx[4] = {0,0,-1,1};
const int Dy[4] = {-1,1,0,0};
int mp[50][50];
int visited[50][50];

int main()
{
   int T;

   cin >> T;

   while(T--)
   {
      int N, M, K;
      int ret = 0;

      cin >> M >> N >> K;

      for(int y = 0; y < N; ++y)
      {
         for(int x = 0; x < M; ++x)
         {
            mp[y][x] = 0;
            visited[y][x] = 0;
         }
      }

      for(int i = 0; i < K; ++i)
      {
         int y, x;

         cin >> x >> y;

         mp[y][x] = 1;
      }

      for(int y = 0; y < N; ++y)
      {
         for(int x = 0; x < M; ++x)
         {
            if(visited[y][x] || mp[y][x] == 0)
               continue;
            else
            {
               queue<pair<int,int>> que;

               que.push(pair<int, int>(y,x));
               ++ret;

               while(!que.empty())
               {
                  visited[que.front().first][que.front().second] = 1;
                  
                  for(int i = 0; i<4; i++)
                  {
                     int u = que.front().first + Dy[i];
                     int v = que.front().second + Dx[i];

                     if(u < 0 || v <0 || u >= N || v >= M)
                        continue;
                     else if(!visited[u][v] && mp[u][v] != 0)
                        que.push(pair<int, int>(u,v));
                  }

                  que.pop();
               }
            }
         }
      }

      cout << ret << "\n";
   }
}