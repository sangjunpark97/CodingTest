#include <bits/stdc++.h>
using namespace std;


int main()
{
   int N, reV = 0;
   vector<int> V;

   cin >> N;

   long long M;

   cin >> M;

   vector<int> vct;

   if(N < 2)
   {
      cout << '0';
      return 0;
   }

   for(int i = 0; i < N; ++i)
   {
      int a;

      cin >> a;

      vct.push_back(a);
   }

   long long sum = 0;

   for(int i = 0; i < (int)vct.size(); ++i)
   {
      for(int j = i + 1; j <(int)vct.size(); ++j)
      {
         sum = vct[i] + vct[j];

         if(sum == M)
            reV++;
      }
   }

   cout << reV;
}