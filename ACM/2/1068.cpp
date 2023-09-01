#include <bits/stdc++.h>
using namespace std;

int ret = 0;
int visited[50] = {0};
vector<int> vctA[50];

void BFS(int n)
{
   if(visited[n])
      return;
   else
   {
      visited[n] = 1;

      if(vctA[n].size() == 0)
         ret++;
      else
      {
         for(int i = 0; i < (int)vctA[n].size(); ++i)
            BFS(vctA[n][i]);
      }
   }
}

int main()
{
   int N;

   cin >> N;

   int start;
   int skip;

   for(int i = 0; i < N; ++i)
   {
      int t;

      cin >> t;

      if(t == -1)
      {
         start = i;
         continue;
      }

      vctA[t].push_back(i);
   }

   cin >> skip;

   for(int i = 0; i < N; ++i)
   {
       vctA[i].erase(remove(vctA[i].begin(), vctA[i].end(), skip), vctA[i].end());
   }

   vctA[skip].clear();

   BFS(start);

   if(skip == start)
      ret = 0;
      
   cout << ret;
}