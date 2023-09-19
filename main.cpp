#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int>> v;

int main()
{
    int N, L;

    cin >> N >> L;
    
    for(int i = 0; i< N; i++)
    {
        int a , b;

        cin>> a >> b;

        v.push_back(pair<int,int>(a,b));
    }

    sort(v.begin(), v.end());

    int start = 2000000000;
    int end = 2000000000;

    int ret = 0;

    while(v.size())
    {
        int r = v.back().second - 1;
        int l = v.back().first;
        
        if(end <= l)
        {
            v.pop_back();
            continue;
        }

        if(start > r)
            start = r;
            
        end = start - L + 1;

        if(end <= l)
            v.pop_back();

        start = end - 1;
        
        ret++;
    }

    cout << ret;
}