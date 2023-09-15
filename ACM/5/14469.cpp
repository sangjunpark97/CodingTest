#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;

    cin >> N;

    vector<pair<int,int>> vctP;

    for(int i = 0; i < N; i++)
    {
        int a, b;

        cin >> a >> b;

        b = a + b;

        vctP.push_back(pair<int, int>(a,b));
    }

    sort(vctP.begin(),vctP.end());

    int r = vctP[0].second;

    for(int i = 1; i < N; i++)
    {
        if(r > vctP[i].first)
        {
            r = vctP[i].second + (r - vctP[i].first);
        }
        else
            r = vctP[i].second;
    }

    cout << r;
}