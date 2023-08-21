#include <bits/stdc++.h>
using namespace std;

const int Dx[4] = {0,0,-1,1};
const int Dy[4] = {-1,1,0,0};
int mp[100][100];
int visited[100][100];

void DFS(int y, int x, int N, int k)
{
   if(visited[y][x])
      return;
   else if(mp[y][x] > k)
   {
      visited[y][x] = 1;

      for(int i = 0; i < 4; ++i)
      {
         int u = y + Dy[i];
         int v = x + Dx[i];

         if(u < 0 || v <0 || u >= N || v >= N)
            continue;

         DFS(u,v, N, k);
      }
   }
}

int main()
{
      int N;

      cin >> N;

      int max = 0;

      for(int y = 0; y < N; ++y)
      {
         for(int x = 0; x < N; ++x)
         {
            int k;

            cin >> k;

            if(max < k)
               max = k;

            mp[y][x] = k;
         }
      }

      int ret = 0;

      for(int k = 0; k < max; ++k)
      {
         int cnt = 0;
         
         for(int y = 0; y < N; ++y)
         {
            for(int x = 0; x < N; ++x)
            {
               visited[y][x] = 0;
            }
         }

         for(int y = 0; y < N; ++y)
         {
            for(int x = 0; x < N; ++x)
            {
               if(visited[y][x] == 0 && mp[y][x] > k)
               {
                  DFS(y,x, N, k);
                  ++cnt;
               }
            }
         }
         if(cnt > ret)
            ret = cnt;
      }

      cout << ret << "\n";
}

