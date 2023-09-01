#include <bits/stdc++.h>
using namespace std;

struct A
{
   int a, b, c;
};

int a[3];
int visited[100][100][100];
int mutal[6][3] = {
	{9, 3, 1}, 
	{9, 1, 3}, 
	{3, 1, 9}, 
	{3, 9, 1}, 
	{1, 3, 9}, 
	{1, 9, 3}
};

queue<A> que;
int m = 999999;

void BFS()
{
   que.push({a[0], a[1], a[2]});
   visited[a[0]][a[1]][a[2]] = 0;

   while(que.size())
   {
      int a = que.front().a;
      int b = que.front().b;
      int c = que.front().c;

      for(int i = 0; i < 6; i++)
      {
         int na = max(0, a - mutal[i][0]);
         int nb = max(0, b - mutal[i][1]);
         int nc = max(0, c - mutal[i][2]);

         if(visited[na][nb][nc] != 0 && visited[na][nb][nc] <= visited[a][b][c] + 1)
            continue;
         
         visited[na][nb][nc] = visited[a][b][c] + 1;
         que.push({na,nb,nc});
      }

      que.pop();
   }
}

int main()
{
   int N;

   cin >> N;

   for(int i = 0; i < N; ++i)
      cin >> a[i];
   
   BFS();

   cout << visited[0][0][0];
}