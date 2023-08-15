#include <bits/stdc++.h>
using namespace std;


int main()
{
   int a[101] = {0};
   int A, B, C;

   cin >> A >> B >> C;
   
   for(int i = 0; i < 3; ++i)
   {
      int t, q;

      cin >> t >> q;

      for(int p = t; p < q; ++p)
      {
         a[p]++;
      }
   }

   int sum = 0;

   for(int i = 0; i < 101; ++i)
   {
      if(a[i] == 1)
         sum+=A;
      if(a[i] == 2)
         sum+=B * 2;
      if(a[i] == 3)
         sum+=C * 3;
   }
   
   cout << sum;
}