#include <bits/stdc++.h>

using namespace std;

int mp[10001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL); 

    int N;

    cin >> N;

    vector<pair<int, int>> vctP;

    for(int i = 0; i < N; i++)
    {
        int a, b;

        cin>> a >> b;

        vctP.push_back(pair<int, int>(a, b));
    }
    
    sort(vctP.begin(), vctP.end());
    reverse(vctP.begin(),vctP.end());

    int V = vctP[0].first;
    int T = vctP[0].second;
    int ret = 0;

    for(int i = 0; i < N; i++)
    {
        V = vctP[i].first;
        T = vctP[i].second;

        while(mp[T] && T!=0)T--;

        if(T != 0)
            mp[T] = V;
    }

    for(int i = 1; i <= 10000; i++)
    {
        ret+=mp[i];
    }

    cout << ret;
}