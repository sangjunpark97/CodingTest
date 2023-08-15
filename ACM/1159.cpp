#include <bits/stdc++.h>
using namespace std;

int main()
{
   int array[26] = {0};
   int a = 0;

   cin >> a;

   for(int i = 0; i < a; ++i)
   {
      string strA;

      cin >> strA;

      array[strA[0] - 'a']++;
   }

   int flag = 0;

   for(int i = 0; i < 26; ++i)
   {
      if(array[i] >= 5)
      {
         cout << char(i + 'a');
         flag++;
      }
   }
   
   if(flag == 0)
      cout << "PREDAJA";
}