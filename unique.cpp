#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> vctA{0, 1, 1, 2, 2, 2, 3, 3, 3, 3 ,2, 1, 2, 3, 4 ,5};

    sort(vctA.begin(), vctA.end());
    vctA.erase(unique(vctA.begin(), vctA.end()), vctA.end());
    for(int i : vctA)
        cout << i << " ";

    return 0;
}