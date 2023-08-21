#include <bits/stdc++.h>
using namespace std;
int mp[64][64];
string ret;

int N;

void Recur(int Y, int X, int n, int cnt)
{
   if(n == 0)
      return;
   else
   {
      bool bCheck = true;

      for(int y= Y; y < Y + n; y++)
      {
         for(int x = X; x < X + n; x++)
         {
            if(mp[Y][X] != mp[y][x])
            {
               bCheck = false;
               break;
            }
         }

         if(!bCheck)
            break;
      }

      if(!bCheck)
      {
         ret+='(';
         Recur(Y, X, n / 2, 1);
         Recur(Y, X + n / 2, n / 2, 2);
         Recur(Y + n / 2, X, n / 2, 3);
         Recur(Y + n / 2, X + n / 2, n / 2, 4);
         ret+=')';
      }
      else
         ret += to_string(mp[Y][X]);
   }
}

int main()
{
   cin >> N;

   for(int y = 0; y < N; ++y)
   {
      for(int x = 0; x < N; ++x)
         scanf("%1d", &mp[y][x]);
   }

   Recur(0, 0, N, 0);

   cout << ret;
}