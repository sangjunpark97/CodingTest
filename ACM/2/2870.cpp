#include <bits/stdc++.h>
using namespace std;

bool IsNumber(char c)
{
   return c >= '0' && c <= '9';
}

bool cmp(string a, string b)
{
   if(a.size() == b.size())
   {
      for(int i = 0; i < (int)a.size(); ++i)
      {
         if(a[i] > b[i])
            return false;
         else if(a[i] < b[i])
            return true;
      }
   }
   else
      return a.size() < b.size();

   return false;
}

int main()
{
   int N;

   cin >> N;

   string S;
   vector<long long> vctI;
   vector<string> vctS;
   vector<string> vctException;

   while(N--)
   {
      cin >> S;

      int right = 0;

      string t;

      while(true)
      {
         if(IsNumber(S[right]) && right <S.size())
            t.push_back(S[right]);
         else if(t.size())
         {
            int k = 0;

            while(t[k] == '0' && t.size() != 1)
               t.erase(k, 1);
            
            vctS.push_back(t);
            t.clear();
         }

         right++;

         if(right >= S.size())
         {
            if(t.size())
            {

            int k = 0;

            while(t[k] == '0' && t.size() != 1)
               t.erase(k, 1);

               vctS.push_back(t);
            }

            break;
         }
      }
   }

   sort(vctS.begin(),vctS.end(), cmp);

   for(auto i : vctS)
      cout << i << endl;
}