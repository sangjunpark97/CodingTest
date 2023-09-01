#include <bits/stdc++.h>
using namespace std;

int mp[1000][1000];
int visited[1000][1000];
int res[1000][1000];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int,int>> queJ;
vector<pair<int, int>> F;
vector<int> vctRes;
int R, C;

void BFS_J()
{
   while(queJ.size())
   {
      int y = queJ.front().first;
      int x = queJ.front().second;

      if(y == 0 || x == 0 || y == R-1 || x == C-1)
         res[y][x] = 1;

      for(int i = 0; i < 4; i++)
      {
         int ny = y + dy[i];
         int nx = x + dx[i];

         if(ny < 0 || nx < 0 || ny >= R || nx >= C || mp[ny][nx])
            continue;

         queJ.push(pair<int,int>(ny,nx));
         mp[ny][nx] = mp[y][x] + 1;
      }
      
      queJ.pop();
   }
}


void BFS_F()
{
   while(queJ.size())
   {
      int y = queJ.front().first;
      int x = queJ.front().second;

      if((mp[y][x] - visited[y][x] < 0) && mp[y][x] > 0 && res[y][x] == 1)
      {
      }
      else
         res[y][x] = 0;

      for(int i = 0; i < 4; i++)
      {
         int ny = y + dy[i];
         int nx = x + dx[i];

         if(ny < 0 || nx < 0 || ny >= R || nx >= C || mp[ny][nx] == -1 || visited[ny][nx])
            continue;
         
         queJ.push(pair<int,int>(ny,nx));
         visited[ny][nx] = visited[y][x] + 1;
      }
      
      queJ.pop();
   }
}

int main()
{
   cin >> R >> C;

   for(int y = 0; y < R; ++y)
   {
      string s;

      cin >> s;
      
      for(int x = 0; x < C; ++x)
      {
         if(s[x] == '#')
            mp[y][x] = -1;
         else if(s[x] == 'J')
         {
            mp[y][x] = 1;
            queJ.push(pair<int, int>(y,x));
         }
         else if(s[x] == 'F')
         {
            mp[y][x] = -2;
            F.push_back(pair<int, int>(y,x));
         }
         else
            mp[y][x] = 0;
      }
   }

   BFS_J();

   for(auto i : F)
   {
      memset(visited, 0, 1000 * 1000 * 4);
      queJ.push(i);
      visited[i.first][i.second] = 1;
      BFS_F();
   }

   for(int y = 0; y < R; ++y)
   {
      for(int x = 0; x < C; ++x)
      {
         if((y == 0 || x == 0 || y == R-1 || x == C-1) && res[y][x])
            vctRes.push_back(mp[y][x]);
      }
   }

   sort(vctRes.begin(), vctRes.end());

   if(vctRes.size())
      cout << vctRes[0];
   else
      cout << "IMPOSSIBLE";
}