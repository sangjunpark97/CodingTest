#include <bits/stdc++.h>
using namespace std;


int main()
{
   int N;
   string str;
   int reV = 0;

   cin >> N;

   while(N--)
   {
      vector<char> vctA;
      cin >> str;
   
      if(str.length() % 2)
         continue;
      
      for(auto i : str)
      {
         if(vctA.size() > 0 && vctA.back() == i)
            vctA.pop_back();
         else
            vctA.push_back(i);
      }

      if(vctA.size() == 0)
         reV++;
   }

   cout << reV;
}