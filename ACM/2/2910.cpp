#include <bits/stdc++.h>
using namespace std;

string str;

bool compare(const pair<int, int>&a, const pair<int, int>&b)
{
   if(a.first > b.first)
      return true;
   else if(a.first == b.first)
      return str.find(to_string(a.second)) < str.find(to_string(b.second));
   else
      return false;
}

int main()
{
   int N, M;
   map<int, int> mp;
   vector<pair<int, int>> vctPair;

   cin >> N >> M;

   for(int i = 0; i < N; ++i)
   {
      int input;

      cin >> input;

      str += to_string(input) + " ";

      mp[input]++;
   }

   for(auto it = mp.begin(); it != mp.end(); ++it)
   {
      vctPair.push_back(pair<int, int>(it->second, it->first));
   }

   sort(vctPair.begin(), vctPair.end(), compare);

   for(auto i : vctPair)
   {
      for(int j = 0; j < i.first; ++j)
      {
         cout << i.second << " ";
      }
   }
}