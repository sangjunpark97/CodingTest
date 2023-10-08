#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int main()
{
    int A, B;
    
    cin >> A >> B;

    vector<string> vA,vB;

    for(int i = 0; i < A; i++)
    {
        string s;

        cin >> s;

        vA.push_back(s);
    }

    for(int i = 0; i < B; i++)
    {
        string s;

        cin >> s;

        vB.push_back(s);
    }

    sort(vA.begin(),vA.end());
    sort(vB.begin(),vB.end());

    int ret = 0;

    while(vB.size())
    {
        if(vB.back() == vA.back())
        {
            ret++;
            string s = vB.back();
            vB.pop_back();

            while(vB.size() && vB.back() == s)
            {
                ret++;
                vB.pop_back();
            }

            vA.pop_back();
        }
        else
            vB.pop_back();
    }

    cout << ret;
}