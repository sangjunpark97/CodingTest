#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

priority_queue<int, vector<int>, less<int>> l;
vector<int> m;
priority_queue<int, vector<int>, greater<int>> r;

int main()
{
    fastio;
    int N;

    cin >> N;

    for(int i = 1; i <= N; i++)
    {
        int num;

        cin >> num;

        if(m.size() == 0)
            m.push_back(num);
        else if(m[0] >= num)
        {
            l.push(num);

        }
        else
        {
            r.push(num);
        }
        
        int ls = l.size();
        int rs = r.size();

        if(ls > rs + 1)
        {
            r.push(m[0]);
            m[0] = l.top();
            l.pop();
        }
        else if(ls + 1 < rs)
        {
            l.push(m[0]);
            m[0] = r.top();
            r.pop();
        }
        else if(i % 2 == 0 && ls > rs)
        {
            r.push(m[0]);
            m[0] = l.top();
            l.pop();
        }
        
        cout << m[0] << "\n";
    }
}