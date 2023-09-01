#include <bits/stdc++.h>
using namespace std;

int ret = 0;
int now = 0;
int visited[10001] = {0};
vector<int> vctRet;
vector<int> vctA[10001];

void BFS(int n, int p)
{
   if(visited[n] == p + 1)
      return;
   else
   {
      visited[n] = p + 1;
      now++;

      for(int i = 0; i < (int)vctA[n].size(); ++i)
         BFS(vctA[n][i], p);
   }
}

int main()
{
   int N, M;

   cin >> N >> M;

   for(int i = 0; i < M; ++i)
   {
      int A, B;

      cin >> A >> B;

      vctA[B].push_back(A); 
   }

   for(int i = 1; i <= N; ++i)
   {
      now = 0;

      BFS(i, i);
      
      if(now > ret)
      {
         ret = now;
         vctRet.clear();
         vctRet.push_back(i);
      }
      else if(now == ret)
         vctRet.push_back(i);
   }

   sort(vctRet.begin(), vctRet.end());

   for(auto i : vctRet)
      cout << i << " ";
}