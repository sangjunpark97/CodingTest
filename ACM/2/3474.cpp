#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
   
   long long N;

   cin >> N;

   long long ret = 0;

   for(int i = 0; i<N; ++i)
   {
      ret = 0;
      int input;

      cin >> input;

      for(int j = 5; j <=input; j *=5)
         ret+= input / j;

      cout << ret << endl;
   }
   
   return 0;
}