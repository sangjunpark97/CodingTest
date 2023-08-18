#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;

   while(scanf("%d", &n) != EOF)
   {
      long long ret = 1;

      if(n == 1)
      {
         cout << 1 << endl;
         continue;
      }

      int cnt = 2;

      while((ret = ((ret % n) * (10 % n) + 1) % n) != 0)
         cnt++;

      cout << cnt << endl;
   }
}