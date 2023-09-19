#include <bits/stdc++.h>

using namespace std;

int mp[101][101];
int snake[101][101];
queue<pair<int,int>> que;

int main()
{
    int N;

    cin >> N;

    int K;

    cin >> K;

    for(int i = 0; i < K; i++)
    {
        int a, b;

        cin >> a >> b;

        mp[a][b] = 1;
    }

    int L;

    cin >> L;

    vector<pair<int,int>> v;

    for(int i = 0; i < L; i++)
    {
        int a;
        string s;

        cin >> a >> s;

        if(s == "D")
            v.push_back(pair<int, int>(a,1));
        else if(s == "L")
            v.push_back(pair<int, int>(a,2));
    }

    reverse(v.begin(), v.end());

    int ret = 0;
    int dir = 0;
    int y = 1, x = 1;

    que.push(pair<int,int>(1,1));

    while(true)
    {
        ret++;

        if(dir == 0)
            x++;
        else if(dir == 1)
            y++;
        else if(dir == 2)
            x--;
        else
            y--;

        if(y < 1 || x < 1 || y > N || x > N)
            break;

        if(snake[y][x] == 1)
            break;

        if(mp[y][x] == 0)
        {
            int ly = que.front().first;
            int lx = que.front().second;

            snake[ly][lx] = 0;
            que.pop();
        }
        else
            mp[y][x] = 0;

        que.push(pair<int,int>(y, x));
        snake[y][x] = 1;

        if(ret == v.back().first)
        {
            if(v.back().second == 1)
                dir = (dir + 1) % 4;
            else
                dir = (dir + 3) % 4; 

            v.pop_back();
        }
    }

    cout << ret;
}