#include <bits/stdc++.h>

using namespace std;

vector<int> vctReturn{0,1,2,3,4};
vector<int> vctI{0,0,1,1,1};

int main()
{
    do
    {
        for(int i : vctI)
        {
            cout << i << " ";
        }
        cout << "\n";
        
    } while (next_permutation(vctI.begin(),vctI.end()));
}