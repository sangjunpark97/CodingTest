#include <bits/stdc++.h>
using namespace std;

int main()
{
   int N;

   cin >> N;
   
   vector<int> vctA, vctB;

   for(int a = 0; a < 10; a++)
   {
      for(int b = 0; b < 10; b++)
      {
         for(int c = 0; c < 10; c++)
         {
            for(int d = 0; d < 10; d++)
            {
               vctA.push_back(a);
            vctA.push_back(b);
            vctA.push_back(c);
            vctA.push_back(d);
            vctA.push_back(666);

            sort(vctA.begin(), vctA.end());

            do
            { 
               if(vctA[0] == 666)
                  vctB.push_back(vctA[0] * 10000 + vctA[1] * 1000 + vctA[2] * 100 + vctA[3]* 10 + vctA[4]);
               else if(vctA[1] == 666)
                  vctB.push_back(vctA[0] * 1000000 + vctA[1] * 1000 + vctA[2] * 100 + vctA[3]* 10 + vctA[4]);
               else if(vctA[2] == 666)
                  vctB.push_back(vctA[0] * 1000000 + vctA[1] * 100000 + vctA[2] * 100 + vctA[3]* 10 + vctA[4]);
               else if(vctA[3] == 666)
                  vctB.push_back(vctA[0] * 1000000 + vctA[1] * 100000 + vctA[2] * 10000 + vctA[3] * 10 + vctA[4]);
               else if(vctA[4] == 666)
                  vctB.push_back(vctA[0] * 1000000 + vctA[1] * 100000 + vctA[2] * 10000 + vctA[3] * 1000 + vctA[4]);
            } while (next_permutation(vctA.begin(), vctA.end()));

            vctA.clear();
            }
         }
      }
   }

   sort(vctB.begin(), vctB.end());

   int pre = 0;

   vector<int> ret;

   ret.push_back(1);

   for(int i = 0; i < vctB.size(); ++ i)
   {
      if(pre != vctB[i])
      {
         ret.push_back(vctB[i]);
         pre = vctB[i];
      }
   }
   
   cout << ret[N];
}