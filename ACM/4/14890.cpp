#include <bits/stdc++.h>
using namespace std;

int N, L;
int mp[100][100];
int visited[100][100];
int ret;

int main()
{
    cin >> N >> L;

    for(int y = 0; y< N; y++)
    {
        for(int x= 0; x < N; x++)
        {
            cin >> mp[y][x];
        }
    }
    
    stack<int> stk;
    stack<int> stkEmpty;

    //가로
    for(int y = 0; y<N; y++)
    {
        bool bError = false;

        stk = stkEmpty;
       
        for(int x = 0; x < N; x++)
        {
            int now = mp[y][x];

            if(stk.size())
            {
                int pre = stk.top();

                if(now - pre == 1)
                {
                    for(int t = 0; t < L; t++)
                    {
                        if(!stk.size() || visited[y][x - t - 1])
                        {
                            bError = true;
                            break;
                        }

                        stk.pop();
                    }

                    if(!bError)
                    {
                        for(int t = 0; t < L; t++)
                            visited[y][x - t -1] = 1;
                    }

                    stk = stkEmpty;
                }
                else if(pre - now == 1)
                {
                    for(int t = 1; t < L; t++)
                    {
                        if(x + t >= N || mp[y][x + t] != now || visited[y][x + t])
                        {
                            bError = true;
                            break;
                        }
                    }

                    if(!bError)
                    {
                        for(int t = 0; t < L; t++)
                            visited[y][x + t] = 1;
                    }
                }
                else if(abs(pre - now) > 1)
                    bError = true;
            }

            if(bError)
            {
                for(int x = 0; x < N; x++)
                    visited[y][x] = 0;
                continue;
            }

            stk.push(now);
        }

        if(bError)
            continue;

        ret++;
    }

    memset(visited, 0, 100 * 100 * 4);

    //세로
    for(int x = 0; x<N; x++)
    {
        bool bError = false;

        stk = stkEmpty;
       
        for(int y = 0; y < N; y++)
        {
            int now = mp[y][x];

            if(stk.size())
            {
                int pre = stk.top();

                if(now - pre == 1)
                {
                    for(int t = 0; t < L; t++)
                    {
                        if(!stk.size() || visited[y - t - 1][x])
                        {
                            bError = true;
                            break;
                        }

                        stk.pop();
                    }

                    if(!bError)
                    {
                        for(int t = 0; t < L; t++)
                            visited[y - t - 1][x] = 1;
                    }

                    stk = stkEmpty;
                }
                else if(pre - now == 1)
                {
                    for(int t = 1; t < L ; t++)
                    {
                        if(y + t >= N || mp[y + t][x] != now || visited[y + t][x])
                        {
                            bError = true;
                            break;
                        }
                    }

                    if(!bError)
                    {
                        for(int t = 0; t < L; t++)
                            visited[y + t][x] = 1;
                    }
                }
                else if(abs(pre - now) > 1)
                    bError = true;
            }

            if(bError)
                continue;

            stk.push(now);
        }

        if(bError)
        {
            for(int y = 0; y < N; y++)
                visited[y][x] = 0;

            continue;
        }

        ret++;
    }

    cout << ret;
}