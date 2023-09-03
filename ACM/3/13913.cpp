#include <bits/stdc++.h>
using namespace std;
int A, B;
int ret = 987654321;
int visited[1000001];
int retCnt = 0;
queue<int> que;
int pre[1000001];
vector<int> vctRes;
int cal(int x, int i)
{
    if(i == 0)
        return x +1;
    else if(i == 1)
        return x -1;
    else
        return x *2;
}
void go()
{
    que.push(A);
    while(que.size())
    {
        int x = que.front();
        if(x == B)
            retCnt++;
        for(int i = 0; i < 3; i++)
        {
            int nx = cal(x, i);
            if(nx < 0 || nx > 100000 || ((visited[nx] < visited[x] + 1) && visited[nx] != 0))
                continue;
            que.push(nx);
            visited[nx] = visited[x] + 1;
            pre[nx] = x;
        }
        que.pop();
    }
}
int main()
{
    cin >> A >> B;
    visited[A] = 1;
    go();
    cout << visited[B] - 1 << "\n";
    for(int i = B; i != A; i = pre[i])
    {
        vctRes.push_back(i);
    }
    vctRes.push_back(A);
    reverse(vctRes.begin(), vctRes.end());
    for(auto i : vctRes)
        cout << i << " ";
}