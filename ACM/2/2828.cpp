#include <bits/stdc++.h>
using namespace std;

int main()
{
   int left, right;
   int N, M, J;
   queue<int> apple;

   cin >> N >> M;
   cin >> J;

   left = 1;
   right = M;

   for(int i = 0; i < J; ++i)
   {
      int a;

      cin >> a;

      apple.push(a);
   }

   int ret = 0;

   while(!apple.empty())
   {
      int place = apple.front();
      
      if(place >= left && place <= right)
      {
         apple.pop();
         continue;
      }
      else if(place < left)
      {
         left--;
         right--;
         ret++;
      }
      else
      {
         left++;
         right++;
         ret++;
      }
   }
   
   cout << ret;
}