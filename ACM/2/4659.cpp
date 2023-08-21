#include <bits/stdc++.h>
using namespace std;

bool IsAEIOU(char c)
{
   return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool IsEEOO(string s)
{
   return s == "ee" || s == "oo";
}

int main()
{
   while(true)
   {
      string input;

      cin >> input;

      if(input == "end")
         break;

      bool bOne = false;
      bool bTwo = true;
      bool bThird = true;

      if(input.size() == 1)
         bOne = IsAEIOU(input[0]);
      else if(input.size() == 2)
      {
         bOne = IsAEIOU(input[0]) || IsAEIOU(input[1]);
         bThird = ((input[0] != input[1]) || IsEEOO(input));
      }
      else
      {
         bOne = IsAEIOU(input[0]) || IsAEIOU(input[1]);
         string w;

         w.push_back(input[0]);
         w.push_back(input[1]);
         bThird = ((input[0] != input[1]) || IsEEOO(w));

         for(int i = 2; i < input.size(); ++i)
         {
            bOne |= IsAEIOU(input[i]);
            bTwo &= !((IsAEIOU(input[i-2]) == IsAEIOU(input[i-1])) && (IsAEIOU(input[i-1]) == IsAEIOU(input[i])));
            string t;
            t.push_back(input[i - 1]);
            t.push_back(input[i]);
            bThird &= ((input[i - 1] != input[i]) || IsEEOO(t));
         }
      }

      if(bOne && bTwo && bThird)
         cout << '<' + input + '>' + " is acceptable.\n";
      else
         cout << '<' + input + '>' + " is not acceptable.\n";
   }
}