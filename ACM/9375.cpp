#include <bits/stdc++.h>
using namespace std;

int main()
{
   int N;

   cin >> N;

   while(N--)
   {
        int s;

        cin >> s;

        map<string, int> mp;

        while(s--)
        {
            string str;

            cin >> str >> str;

            mp[str]++;
        }

        int sum = 1;

        for(auto i : mp)
            sum *= (i.second + 1);

        cout << sum - 1;
   }
}