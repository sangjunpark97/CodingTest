#include <bits/stdc++.h>

using namespace std;

vector<int> vctA;

void Swap(int t, int q)
{
    int tmp = vctA[t];

    vctA[t] = vctA.at(q);
    vctA[q] = tmp;
}

void RecursivePermutation(int n, int r, int depth)
{
    if(r == depth)
    {
        for(int i = 0; i < vctA.size(); ++i)
        {
            cout << vctA[i] << " ";
        }
        cout << "\n";

        return;
    }

    for(int i = depth; i < n; ++i)
    {
        Swap(i, depth);     
        RecursivePermutation(n, r, depth+1);
        Swap(i, depth);
    }
}

int main()
{
   vctA.push_back(1);
   vctA.push_back(2);
   vctA.push_back(3);
   vctA.push_back(4);
   RecursivePermutation(4, 4, 0);
}