#include <bits/stdc++.h>
using namespace std;

int main()
{
   string strI;
   char odd;
   map<char, int> mp;

   cin >> strI;

   bool bOdd = strI.length() % 2;

   for(auto i : strI)
      mp[i]++;

   sort(strI.begin(), strI.end());

   if(!bOdd)
   {
      for(auto iter = mp.begin(); iter != mp.end(); iter++)
      {
         if(iter->second % 2 == 1)
         {
            cout << "I'm Sorry Hansoo";
            exit(0);
         }
      }
   }
   else
   {
      int a = 0;

      for(auto iter = mp.begin(); iter != mp.end(); iter++)
      {
         if(iter->second % 2 == 1)
         {
            a++;
            odd = iter->first;
         }
      }

      if(a != 1)
      {
         cout << "I'm Sorry Hansoo";
         exit(0);
      }
   }


      string strO;
      
      for(auto iter = mp.begin(); iter != mp.end(); iter++)
      { 
         for(int i = 0; i < iter->second / 2 ; ++i)
            strO += iter->first;
      }
      
      string strR = strO;

      reverse(strR.begin(), strR.end());

   if(bOdd)
      strO = strO + odd;

   strO = strO + strR;

   cout << strO;
}