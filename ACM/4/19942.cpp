#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int mp, mf, ms, mv;
    int p[15],f[15],s[15],v[15],c[15];
    int ret = INT_MAX;

    cin >> N;
    cin >> mp >> mf >> ms >> mv;

    for(int i = 0; i < N ; i++)
    {
        cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
    }

    vector<int> vctRet;
    string strRet;

    for(int i = 0; i < pow(2,N); i++)
    {
        int sp = 0, sf = 0, ss =0, sv = 0, sc = 0;
        vector<int> vctI;
        string strI;

        for(int j = 0; j < N; j++)
        {
            if(i & (1 << j))
            {
                sp += p[j];
                sf += f[j];
                ss += s[j];
                sv += v[j];
                sc += c[j];

                vctI.push_back(j);
                strI.push_back('0' + j);
            }
        }

        if(sp >= mp && sf >= mf && ss >=ms && sv >= mv)
        {
            if(ret >= sc)
            {
                if(ret == sc)
                {
                    if(strRet > strI)
                    {
                        strRet = strI;
                        vctRet = vctI;
                    }
                }
                else
                {
                    strRet = strI;
                    vctRet = vctI;
                }

                ret = sc;
            }   
        }
    }

    if(vctRet.size())
    {
        cout << ret << "\n";
    
        for(auto i : vctRet)
            cout << i + 1 << " ";
    }
    else
    {
        cout << "-1";
    }
}