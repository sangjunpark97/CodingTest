#include <bits/stdc++.h>
using namespace std;


int main()
{
   int a[33] = {0};
   long long A,B,C;
   long long ret;
   int cnt = 0;

   cin >> A >> B >> C;

   ret = A % C;
   a[cnt] = ret;

   while(true)
   {
      cnt++;

      if(pow(2, cnt) >= B)
         break;

      ret = ((ret % C) * (ret % C)) % C;

      a[cnt] = ret;
   }

   cnt--;

   B = B - pow(2,cnt);

   while(B != 0)
   {
      ret = ((ret % C) * (a[(int)log(B)] % C)) % C;
      cnt = log(B);
      B = B - pow(2, cnt);
   }
   
   cout << ret << endl;
}