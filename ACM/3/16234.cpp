#include <bits/stdc++.h>
using namespace std;

int mp[50][50];
int visited[50][50];
int N, L, R;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

vector<pair<int, int>> vctI;
vector<vector<pair<int, int>>> vctVctI;

void DFS(int y, int x)
{
   visited[y][x] = 1;
   vctI.push_back(pair<int, int>(y,x));

   for(int i = 0; i < 4; i++)
   {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if(ny < 0 || nx < 0 || ny >= N || nx >= N || visited[ny][nx])
         continue;
      else if(abs(mp[y][x] - mp[ny][nx]) >= L && abs(mp[y][x] - mp[ny][nx]) <= R)
         DFS(ny,nx);
   }
}

int main()
{
   cin >> N >> L >> R;

   for(int y = 0; y < N; ++y)
   {
      for(int x = 0; x < N; ++x)
      {
         cin >> mp[y][x];
      }
   }

   int ret = 0;

   do
   {
      vctI.clear();
      vctVctI.clear();
      memset(visited, 0, 50*50*4);

      for(int y = 0; y < N; ++y)
      {
         for(int x = 0; x < N; ++x)
         {
            if(visited[y][x] == 0)
            {
               DFS(y,x);

               if(vctI.size() > 1)
                  vctVctI.push_back(vctI);
               
               vctI.clear();
            }
         }
      }


      for(auto pVctI : vctVctI)
      {
         int sum = 0;
         int cnt = 0;

         for(auto i : pVctI)
         {
            cnt++;
            sum += mp[i.first][i.second];
         }

         for(auto i : pVctI)
            mp[i.first][i.second] = sum / cnt;
      }

      if(vctVctI.size())
         ret++;

   } while (vctVctI.size());

   cout << ret;
}