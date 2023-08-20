#include <bits/stdc++.h>
using namespace std;

int main()
{
   int N, k;
   int psum[100001] = {0};
   
   cin >> N >> k;

   for(int i = 1; i <= N; ++i)
   {
      int k;
      
      cin >> k;

      psum[i] = psum[i - 1] + k;
   }

   int max = INT32_MIN;

   for(int i = k; i <= N; ++i)
   {
      int sum = psum[i] - psum[i - k];

      if(sum > max)
         max = sum;
   }

   cout << max;
}