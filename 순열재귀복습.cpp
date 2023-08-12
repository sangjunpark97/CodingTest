#include <bits/stdc++.h>

using namespace std;

vector<int> vctTmp;

void Permutation(int i32Now, int i32Count, int i32Depth)
{
    if(i32Depth == i32Count)
    {
        for(int i32I = 0; i32I < i32Count; ++i32I)
            cout << vctTmp[i32I] << " ";

        cout << "\n";

        return;
    }

    for(int32_t i32I = i32Depth; i32I < i32Now; ++i32I)
    {
        swap(vctTmp[i32Depth], vctTmp[i32I]);
        Permutation(i32Now, i32Count, i32Depth + 1);
        swap(vctTmp[i32I], vctTmp[i32Depth]);
    }
}

int main()
{
    vctTmp.push_back(0);
    vctTmp.push_back(1);
    vctTmp.push_back(2);
    vctTmp.push_back(3);

    Permutation(4, 4, 0);
}