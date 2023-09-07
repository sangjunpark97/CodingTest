#include <bits/stdc++.h>
using namespace std;

vector<int> vct;

int main()
{
    int n;

    cin >> n;

    if(n == 64)
    {
        cout << 1;
        return 0;
    }
    
    vct.push_back(64);

    while(true)
    {
        int sum = 0;
        int now = vct.back();

        vct.pop_back();
        vct.push_back(now / 2);
        vct.push_back(now / 2);

        for(auto i : vct)
        {
            sum += i;
        }

        if(sum - vct.back() == n)
        {
            cout << vct.size() - 1;
            return 0;
        }
        else if(sum - vct.back() > n)
        {
            vct.pop_back();
        }
    }
}