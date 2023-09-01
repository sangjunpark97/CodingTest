#include <bits/stdc++.h>
using namespace std;

int visited[50][50];
int mp[50][50];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
queue<pair<int, int>> que;
int N, M;
int cnt[100][13];

void BFS(int house)
{
   while(que.size())
   {
      int y = que.front().first;
      int x = que.front().second;

      if(mp[y][x] > 1 && cnt[house][mp[y][x] - 2] == 0)
         cnt[house][mp[y][x] - 2] = visited[y][x] - 1;

      for(int i = 0; i < 4; i++)
      {
         int ny = y + dy[i];
         int nx = x + dx[i];

         if(ny < 0 || nx < 0 || nx >= N || ny >= N || visited[ny][nx])
            continue;
         else
         {
            que.push(pair<int,int>(ny, nx));
            visited[ny][nx] = visited[y][x] + 1;
         }
      }

      que.pop();
   }
}

int main()
{
   cin >> N >> M;

   int chicken = 0;
   memset(cnt, 0, 13*100 * 4);

   for(int y = 0; y < N; ++y)
   {
      for(int x = 0; x < N; ++x)
      {
         cin >> mp[y][x];

         if(mp[y][x] == 2)
         {
            mp[y][x] += chicken;
            chicken++;
         }
      }
   }
   
   int house = 0;

   for(int y = 0; y < N; ++y)
   {
      for(int x = 0; x < N; ++x)
      {
         if(mp[y][x] == 1)
         {
            memset(visited, 0, 50 * 50 * 4);
            que.push(pair<int, int>(y,x));
            visited[y][x] = 1;
            BFS(house);
            house++;
         }
      }
   }

   vector<int> vctComb;

   for(int i = 0; i < chicken; ++i)
      vctComb.push_back(0);
   
   for(int i = 0; i < M; ++i)
      vctComb[i] = 1;
   
   sort(vctComb.begin(), vctComb.end());

   int min = 9999999;

   do
   {
      int sum = 0;

      for(int i = 0; i < house; ++i)
      {
         int minDist = 999999;

         for(int j = 0; j < vctComb.size(); ++j)
         {
            if(vctComb[j] == 1)
            {
               minDist = minDist > cnt[i][j] ? cnt[i][j] : minDist; 
            }
         }

         sum += minDist;
      }
      
      if(min > sum)
         min = sum;
   } while (next_permutation(vctComb.begin(), vctComb.end()));
   
   cout << min;
}