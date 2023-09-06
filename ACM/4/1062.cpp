#include <bits/stdc++.h>
using namespace std;

vector<string> vctS;
vector<int> vctI;

int global[26];
int region[26];

int main()
{
    int N, K;

    cin >> N >> K;

    for(int i = 0; i < N; i++)
    {
        string s;

        cin >> s;

        s.erase(s.end() - 4, s.end());
        s.erase(s.begin(), s.begin() + 4);

        vctS.push_back(s);

        int num = 0;

        for(int j = 0; j < s.length(); j++)
        {
            num = num | (1 << (s[j] - 'a'));
        }

        vctI.push_back(num);
    }

    if(K < 5)
    {
        cout << "0";
        return 0;
    }

    int ret = 0;

    if(K == 5)
    {
         int num = 0;
        num =  num | (1 << ('a' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a'))| (1 << ('c' - 'a'))| (1 << ('i' - 'a'));
        
        for(int i = 0; i < vctI.size(); i++)
        {
            if((vctI[i] & num) == vctI[i])
                ret++;
        }

        cout << ret;

        return 0;
    }

    int k = K - 5;

    vector<int> A;

    A.resize(26,0);
    
    for(int i = 0; i < k; i++)
        A[i] = 1;


    sort(A.begin(), A.end());

    do
    {
        int cnt = 0;

        if(A['a' - 'a'] || A['n' - 'a'] || A['t' - 'a'] || A['c' - 'a'] || A['i' - 'a'])
            continue;

        int num = 0;
        num =  num | (1 << ('a' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a'))| (1 << ('c' - 'a'))| (1 << ('i' - 'a'));
        
        for(int i = 0; i<A.size(); i++)
        {
            if(A[i])
            {
                num = num | (1 << i);
            }   
        }

        for(int i = 0; i < vctI.size(); i++)
        {
            if((vctI[i] & num) == vctI[i])
                cnt++;
        }

        ret = max(ret, cnt);
    } while (next_permutation(A.begin(), A.end()));

    cout << ret;
}