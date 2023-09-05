#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    int mp, mf, ms, mv;
    int p[15],f[15],s[15],v[15],c[15];
    int ret = 987654321;

    cin >> N;
    cin >> mp >> mf >> ms >> mv;

    for(int i = 0; i < N ; i++)
    {
        cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
    }

    vector<int> vctRet;

    for(int i = 0; i < pow(2,N); i++)
    {
        int sp = 0, sf = 0, ss =0, sv = 0, sc = 0;
        vector<int> vctI;

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
            }
        }

        if(sp >= mp && sf >= mf && ss >=ms && sv >= mv)
        {
            if(ret > sc)
            {
                ret = sc;
                vctRet.clear();
                vctRet = vctI;
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