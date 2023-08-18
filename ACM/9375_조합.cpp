#include <bits/stdc++.h>
using namespace std;

int main()
{
   int N;

   cin >> N;

   for(int i = 0; i < N; ++i)
   {
      vector<pair<int, string>> vct;

      int s;

      cin >> s;

      for(int t = 0; t < s; ++ t)
      {
         string kind;

         cin >> kind;
         cin >> kind;

         if(vct.size() == 0)
         {
            vct.push_back(pair<int, string>(1, kind));
            continue;
         }
      
         bool bCheck = false;

         for(int j = 0; j < (int)vct.size(); ++j)
         {
            if(kind == vct[j].second)
            {
               vct[j].first++;
               bCheck = true;
            }
         }

         if(!bCheck)
            vct.push_back(pair<int, string>(1, kind));
      }

      int sum = 0;

      for(int p = 0; p < vct.size(); ++p)
      {
         vector<int> vctFlag;

         for(int j = 0; j <p; ++j)
            vctFlag.push_back(0);
         
         for(int j = p; j<vct.size(); ++j)
            vctFlag.push_back(1);

         do
         {
            int result = 1;
         
            for(int j = 0; j < vctFlag.size(); ++j)
            {
               if(vctFlag[j])
                  result *= vct[j].first;
            }

            sum += result;
         } while (next_permutation(vctFlag.begin(), vctFlag.end()));
      }

      cout << sum;
   }
}