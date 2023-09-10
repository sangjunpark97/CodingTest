#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 


    int N;
    vector<pair<int, int>> vctP;
    
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int a;
        int b;

        cin >> a >> b;

        vctP.push_back(pair<int,int>(a,b));
    }

    sort(vctP.begin(), vctP.end());

    int l, r;

    l = vctP[0].first;
    r = vctP[0].second;
    int ret = 0;

    for(int i = 1; i < vctP.size(); i++)
    {
        if(vctP[i].first >= l && vctP[i].first <= r)
        {
            if(r < vctP[i].second)
                r = vctP[i].second;
        }
        else
        {
            ret += r - l;
            l = vctP[i].first;
            r = vctP[i].second;
        }
    }

    ret += r - l;

    cout << ret;
}