#include <bits/stdc++.h>
using namespace std;

int main()
{
   string strA;

   cin >> strA;

   string strB = strA;

   reverse(strA.begin(),strA.end());

   if(strB == strA)
      cout << 1;
   else 
      cout << 0;
}