#include <bits/stdc++.h>
using namespace std;

int a[9];
void combi(int start, vector<int>b);


void print(vector <int>b)
{
    sort(b.begin(), b.end());

      for (int i = 0; i < 7; i++)
         cout << b[i] << endl;
    
    exit(0);
}

void combi(int start, vector<int> b)
{
   if (b.size() == 7)
   {
        if(accumulate(b.begin(), b.end(), 0) == 100)
            print(b);
        else
            return;
   }
   
   for (int i = start + 1; i < 9; i++)
   {
      b.push_back(a[i]);
      combi(i, b);
      b.pop_back();
   }
   return;

}

int main()
{
   for (int i = 0; i < 9; i++)
      cin >> a[i];

   vector<int>b;
   combi(-1, b);
}