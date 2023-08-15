#include <bits/stdc++.h>
using namespace std;

int main()
{
   string strA;

    getline(cin, strA); 

   for(int i = 0; i < strA.length(); ++i)
   {
      if(isupper(strA[i]))
      {
         char tmp = strA[i] + 13;
         
         if(!isupper(tmp))
            tmp -= 26;

         cout << tmp;
      }
      else if(islower(strA[i]))
      {
         char tmp = strA[i] + 13;

         if(!islower(tmp))
            tmp -= 26;
         
         cout << tmp;
      }
      else
         cout << strA[i];
   }
}