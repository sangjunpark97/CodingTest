#include <bits/stdc++.h>

using namespace std;

vector<int> vctA;
vector<int> vctRes;

void RecursiveCombi(int n, int r, int start)
{
    if(vctRes.size() == r)
    {
        for(int i =0; i<r; ++i)
            cout << vctRes[i] << " ";
        
        cout << "\n";
        return;
    }

    for(int i = start + 1; i < n; i++)
    {
        vctRes.push_back(vctA[i]);
        RecursiveCombi(n, r, i);
        vctRes.pop_back();
    }
}

int main()
{
   vctA.push_back(0);
   vctA.push_back(1);
   vctA.push_back(2);
   vctA.push_back(3);
   vctA.push_back(4);
   
   RecursiveCombi(5, 3, -1);
}