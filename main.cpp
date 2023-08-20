#include <bits/stdc++.h>
using namespace std;

vector<int> adj[5];
bool visited[5] = {false};

void DFS(int v)
{
   visited[v] = true;

   for(auto i : adj[v])
   {
      if(visited[i] == false)
         DFS(i); 
   }
}

int main()
{
}