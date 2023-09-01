#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n;

   cin >> n;

   while(n--)
   {
      vector<char> vctA;
      string s;

      cin >> s;

      for(int i = 0; i < s.length(); ++i)
      {
         if(vctA.size())
         {
            if(vctA.back() == '(' && s[i] == ')')
               vctA.pop_back();
            else
               vctA.push_back(s[i]);
         }
         else
            vctA.push_back(s[i]);
      }

      if(vctA.size())
         cout << "NO\n";
      else
         cout << "YES\n";
   }
}