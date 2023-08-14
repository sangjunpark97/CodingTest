#include <bits/stdc++.h>

using namespace std;

vector<int> vctInput;

int main()
{
    for(int i = 0; i < 9; i++)
    {
        int i32Input;
        cin >> i32Input;
        vctInput.push_back(i32Input);
    }

    int sum = accumulate(vctInput.begin(), vctInput.end(), 0);

    for(int i = 0; i < 8; ++i)
    {
        for(int j = i + 1; j < 9; ++j)
        {
            if(sum - vctInput[i] - vctInput[j] == 100)
            {
                vctInput.erase(vctInput.begin() + j);
                vctInput.erase(vctInput.begin() + i);
                sort(vctInput.begin(), vctInput.end());

                for(int i : vctInput)
                    cout << i << "\n";
                    
                exit(0);
            }
        }
    }

    return 0;
}