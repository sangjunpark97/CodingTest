#include <bits/stdc++.h>
using namespace std;

int num[10] = {0,1,2,3,4,5,6,7,8,9};
string s;
long long maxN = 0;
long long minN = 9876543210;
long long num0[11] = {0, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000};

bool Check(string s, string n)
{
    bool bReturn = true;

    for(int i = 0; i< s.length(); ++i)
    {
        if(s[i] == '>' && n[i] <= n[i + 1])
            bReturn = false;
        else if(s[i] == '<' && n[i] >= n[i + 1])
            bReturn = false;
    }

    return bReturn;
}

int main()
{
    int k;
    vector<int> vctN;

    cin >> k;

    for(int i = 0; i<k; ++i)
    {
        char a;

        cin >> a;

        s.push_back(a);
        vctN.push_back(1);
    }

    vctN.push_back(1);
    
    for(int i = k; i < 9; ++i)
        vctN.push_back(0);

    sort(vctN.begin(), vctN.end());

    do
    {
        string strRes;

        for(int i = 0; i<vctN.size(); ++i)
        {
            if(vctN[i] == 1)
                strRes.push_back(i + '0');
        }

        do
        {
            if(Check(s, strRes))
            {
                long long n = stoll(strRes);

                if(maxN < n)
                    maxN = n;
                
                if(minN > n)
                    minN = n;
            }
        } while (next_permutation(strRes.begin(), strRes.end()));
    } while (next_permutation(vctN.begin(), vctN.end()));
    
    if(maxN / num0[k] == 0)
        cout << 0;

    cout << maxN << "\n";

    if(minN / num0[k] == 0)
        cout << 0;
    
    cout << minN;
}