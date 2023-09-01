#include <bits/stdc++.h>
using namespace std;

int mp[102][102];
int visited[102][102];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void DFS(int y, int x)
{
   if(mp[y][x] == 1 && visited[y][x] == 0)
   {
      visited[y][x] = 2;
      mp[y][x] = 0;
      return;
   }
   else if(mp[y][x] == 0 && visited[y][x] == 0)
   {
      visited[y][x] = 1;
      
      for(int i = 0; i < 4; ++i)
      {
         int u = y + dy[i];
         int v = x + dx[i];

         if(u < 0 || v < 0 || u > 101 || v > 101)
            continue;
         else
            DFS(u,v);
      }
   }
}

int main()
{
   int N, M;

   cin >> N >> M;

   for(int y = 0; y < 102; ++y)
   {
      for(int x = 0; x < 102; ++x)
      {
         mp[y][x] = 0;
         visited[y][x] = 0;
      }
   }

   for(int y = 1; y <= N; ++y)
   {
      for(int x = 1; x <= M; ++x)
      {
         int v;

         cin >> v;
         mp[y][x] = v;
      }
   }

   int now = 1;
   int prev = 1;
   int ret = 0;

   while(now != 0)
   {
      prev = now;
      now = 0;
      DFS(0,0);

      for(int y = 0; y < 102; ++y)
      {
         for(int x = 0; x < 102; ++x)
         {
            if(visited[y][x] == 2)
               now++;

            visited[y][x] = 0;
         }
      }

      if(now != 0)
         ret++;
   }

   cout << ret << "\n" << prev;
}