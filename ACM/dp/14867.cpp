#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int a, b, c, d;

queue<pair<int, int>> q;
map<pair<int,int>, int> mp;

void BFS()
{
    while(q.size())
    {
        int A = q.front().first;
        int B = q.front().second;

        for(int i = 0; i <= 5; i++)
        {
            pair<int,int> test;

            if(i == 0)
                test = pair<int,int>(a,B);
            else if(i == 1)
                test = pair<int,int>(A,b);
            else if(i == 2)
                test = pair<int, int>(0,B);
            else if(i == 3)
                test = pair<int, int>(A,0);
            else if(i == 4)
            {
                int water = min(A, b - B);

                test = pair<int,int>(A - water, B + water);
            }
            else if(i == 5)
            {
                int water = min(a - A, B);

                test = pair<int,int>(A + water, B -  water);
            }

            if(mp[test] == 0)
            {
                mp[test] = mp[pair<int,int>(A,B)] + 1;
                q.push(test);
            }
        }

        q.pop();
    }
}

int main()
{
    cin >> a >> b >> c >> d;

    q.push(pair<int,int>(0,0));

    BFS();

    if(c == 0 && d == 0)
        cout << "0";
    else if(mp[pair<int,int>(c,d)] == 0)
        cout << "-1";
    else
        cout << mp[pair<int,int>(c,d)];
}