#include <bits/stdc++.h>

using namespace std;

vector<int> vctTmp;

void Combi(int i32Now, int i32Max, int i32Size, vector<int> vctI32Res)
{
    if(i32Max == vctI32Res.size())
    {
        for(int i32I = 0; i32I < i32Max; ++i32I)
            cout << vctI32Res[i32I] << " ";
        
        cout << "\n";

        return;
    }

    for(int i32I = i32Now + 1; i32I < i32Size; ++i32I)
    {
        vctI32Res.push_back(i32I);
        Combi(i32I, i32Max, i32Size, vctI32Res);
        vctI32Res.pop_back();
    }
}

int main()
{
    vctTmp.push_back(0);
    vctTmp.push_back(1);
    vctTmp.push_back(2);
    vctTmp.push_back(3);

    vector<int> vctI32Res;

    Combi(-1, 3, 5, vctI32Res);
}