#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
   vector<pair<int, int>> vctA;
   int win1 = 0, win2 = 0;

   cin >> N;

   while(N--)
   {
      int team;
      string time;

      cin >> team >> time;

      if(vctA.size())
      {
         if(vctA.back().first == team)
            vctA.push_back(pair<int, int>(team, stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2))));
         else if(vctA.size() == 1)
         {
            if(vctA.front().first == 1)
               win1 += stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2)) - vctA.front().second;
            else
               win2 += stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2)) - vctA.front().second;

            vctA.pop_back();
         }
         else
            vctA.pop_back();
      }
      else
         vctA.push_back(pair<int, int>(team, stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2))));
   }

   if(vctA.size())
   {
      if(vctA.front().first == 1)
         win1 += 48 * 60 - vctA.front().second;
      else
         win2 += 48 * 60 - vctA.front().second;
   }

   int a,b;

   a = win1 / 60; b = win1 % 60;

   if(a < 10 && b < 10)
      cout << "0" << win1 / 60 << ":" << "0" <<  win1 % 60 << "\n";
   else if(a < 10)
      cout << "0" << win1 / 60 << ":" << win1 % 60 << "\n";
   else if(b < 10)
      cout << win1 / 60 << ":" << "0" <<  win1 % 60 << "\n";
   else
      cout << win1 / 60 << ":" << win1 % 60 << "\n";

   a = win2 / 60; b = win2 % 60;

   if(a < 10 && b < 10)
      cout << "0" << win2 / 60 << ":" << "0" <<  win2 % 60 << "\n";
   else if(a < 10)
      cout << "0" << win2 / 60 << ":" << win2 % 60 << "\n";
   else if(b < 10)
      cout << win2 / 60 << ":" << "0" <<  win2 % 60 << "\n";
   else
      cout << win2 / 60 << ":" << win2 % 60 << "\n";
}