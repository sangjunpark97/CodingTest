#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mp[13][13];
vector<int> board[13][13];
pair<int,int> pos[11];

int main()
{
    int N, K;

    cin >> N >> K;

    for(int y = 1; y <= N; y++)
    {
        for(int x = 1; x <= N; x++)
            cin >> mp[y][x];
    }

    for(int i = 1; i <= K; i++)
    {
        int y, x, dir;

        cin >> y >> x >> dir;

        pos[i].first = (y - 1) * N + x - 1;
        pos[i].second = dir;

        board[y][x].push_back(i);
    }

    int ret = 0;

    while(true)
    {
        ret++;

        bool bAgain = false;
        bool bStop = false;

        for(int i = 1; i <= K; i++)
        {
            int y = pos[i].first / N + 1;
            int x = pos[i].first % N + 1;
            int dir = pos[i].second;


            int idx = find(board[y][x].begin(), board[y][x].end(), i) - board[y][x].begin(); 

            int ny, nx;
            
            if(dir == 1)
            {
                ny = y;
                nx = x + 1;
            }
            else if(dir == 2)
            {
                ny = y;
                nx = x - 1;
            }
            else if(dir == 3)
            {
                ny = y - 1;
                nx = x;
            }
            else
            {
                ny = y + 1;
                nx = x;
            }


            if(ny < 1 || nx < 1 || ny >N || nx > N || mp[ny][nx] == 2)
            {
                if(bAgain == true)
                {
                    bAgain = false;
                    continue;
                }
                else
                {
                    if(pos[i].second == 2 || pos[i].second == 4)
                        pos[i].second--;
                    else
                        pos[i].second++;

                    bAgain = true;
                    i--;
                    continue;
                }
            }
            else if(mp[ny][nx] == 0)
            {
                bAgain = false;

                for(int v = idx; v < board[y][x].size(); v++)
                {
                    board[ny][nx].push_back(board[y][x][v]);
                    pos[board[y][x][v]].first = (ny - 1) * N + nx - 1;
                }
            }
            else if(mp[ny][nx] == 1)
            {
                bAgain = false;

                for(int v = board[y][x].size() - 1; v >= idx; v--)
                {
                    board[ny][nx].push_back(board[y][x][v]);
                    pos[board[y][x][v]].first = (ny - 1) * N + nx - 1;
                }
            }

            

            while(board[y][x].size() != idx)
                board[y][x].pop_back();

            if(board[ny][nx].size() >= 4)
            {
                bStop = true;
                break;
            }
        }
        
        if(bStop || ret > 1000)
            break;
    }

    if(ret > 1000)
        cout << -1;
    else
        cout << ret;
}