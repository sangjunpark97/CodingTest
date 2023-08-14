#include <bits/stdc++.h>

using namespace std;

vector<int> vctReturn;
vector<int> vctInput;
int a = 0;

int main()
{
    for(int i = 0; i < 9; i++)
    {
        int i32Input;
        cin >> i32Input;
        vctInput.push_back(i32Input);
    }

    vector<int> vctFlag{0,0,1,1,1,1,1,1,1};

    do
    {
        int sum = 0;
        
        for(int i = 0; i<vctFlag.size(); ++i)
        {
            if(vctFlag[i])
            {
                sum += vctInput[i];
            }
        }

        if(sum == 100)
            {
                for(int i = 0; i < vctFlag.size(); ++i)
                {
                    if(vctFlag[i])
                    {
                        vctReturn.push_back(vctInput[i]);
                    }
                }
                
                sort(vctReturn.begin(), vctReturn.end());

                for(int i : vctReturn)
                    cout << i << "\n";

                break;
            }
    } while (next_permutation(vctFlag.begin(), vctFlag.end()));
}