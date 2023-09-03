#include <bits/stdc++.h>
using namespace std;
int A, B;
int ret = 987654321;
int visited[5000001];
queue<int> que;

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

        for(int i = 0; i < 3; i++)
        {
            int nx = cal(x, i);
            if(nx == A || nx < 0 || nx > 500000 || ((visited[nx] < visited[x] + 1) && visited[nx] != 0))
                continue;

            que.push(nx);
            visited[nx] = visited[x] + 1;
        }
        que.pop();
    }
}
int main()
{
    cin >> A >> B;
    go();

    for(int i = 0; ; i++)
    {
        B += i;

        if(B > 500000)
        {
            cout << "-1";
            break;
        }

        if(i >= visited[B])
        {
            if((i - visited[B]) % 2 == 0)
            {
                cout << i;
                break;
            }
        }
    }
}