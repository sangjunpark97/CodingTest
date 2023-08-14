#include <bits/stdc++.h>

using namespace std;

vector<int> vctReturn;
vector<int> vctInput;
int a = 0;

void RecursiveCombi(int n, int r, int start)
{
    if(!a && vctReturn.size() == 7 && accumulate(vctReturn.begin(), vctReturn.end(), 0) == 100)
    {
        sort(vctReturn.begin(), vctReturn.end());
        a = 1;
        for(int i : vctReturn)
            cout << i << "\n";
        
        return;
    }

    for(int i = start + 1; i < r; ++i)
    {
        vctReturn.push_back(vctInput[i]);
        RecursiveCombi(n, r, i);
        vctReturn.pop_back();
    }
}

int main()
{
    for(int i = 0; i < 9; i++)
    {
        int i32Input;
        cin >> i32Input;
        vctInput.push_back(i32Input);
    }
    RecursiveCombi(7, 9, -1);
}