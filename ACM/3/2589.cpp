#include <bits/stdc++.h>
using namespace std;

int mp[50][50];
int visited[50][50];
int N, M;
queue<pair<int, int>> que;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS()
{
   int ret;

   while(que.size())
   {
      int y = que.front().first;
      int x = que.front().second;

      for(int i = 0; i < 4; i++)
      {
         int ny = y + dy[i];
         int nx = x + dx[i];

         if(nx < 0 || ny < 0 || ny >= N || nx >= M || visited[ny][nx] || mp[ny][nx] == 1)
            continue;

         que.push(pair<int,int>(ny,nx));
         visited[ny][nx] = visited[y][x] + 1;
      }

      que.pop();
      ret = visited[y][x] - 1;
   }

   return ret;
}

int main()
{
   cin >> N >> M;

   string s;

   for(int i = 0; i < N; ++i)
   {
      cin >> s;

      for(int j = 0; j < s.length(); ++j)
      {
         if(s[j] == 'W')
            mp[i][j] = 1;
         else
            mp[i][j] = 0;
      }
   }

   int max = 0;

   for(int y = 0; y < N; ++y)
   {
      for(int x = 0; x < M; ++x)
      {
         if(mp[y][x] == 0)
         {
            memset(visited, 0, 50*50*4);
            visited[y][x] = 1;
            que.push(pair<int, int>(y, x));
            int now = BFS();

            if(max < now)
               max = now;
         }
      }
   }

   cout << max;
}