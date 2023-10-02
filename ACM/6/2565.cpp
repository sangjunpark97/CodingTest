#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N;
vector<pair<int, int>> v;
int mp[101];
int lis[101];

bool cmp(pair<int,int>& a, pair<int, int> & b)
{
    if(a.second == b.second)
        return a.first < b.first;
    else
        return a.second < b.second;
}

int main()
{
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        int a,b;

        cin >> a >> b;

        v.push_back(pair<int,int>(a,b));
    }

    sort(v.begin(),v.end(),cmp);
    
    for(int i = 0; i < N; i++)
        mp[i] = v[i].first;

    int len = 0;

    for(int i = 0; i < N; i++)
    {
        auto t = upper_bound(lis, lis + len, mp[i]);

        if(*t == 0) len++;
        *t = mp[i];
    }
    
    cout << N - len;
}