#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int mp[20][20];
int tmp[20][20];
int shark[500][3];
int N, M, k;
pair<int,int> smell[20][20];
int priority[500][5][5];
int sharkNum;
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0,  0, -1, 1};

void move(int Idx, int nowDir)
{
    int y = shark[Idx][0];
    int x = shark[Idx][1];

    //빈 칸
    for(int i = 1; i<=4; i++)
    {
        int moveDir = priority[Idx][nowDir][i];
        
        int ny = y + dy[moveDir];
        int nx = x + dx[moveDir];

        if(ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;
        if(smell[ny][nx].first != 0)
            continue;
        
        shark[Idx][0] = ny;
        shark[Idx][1] = nx;
        shark[Idx][2] = moveDir;

        return;
    }

    for(int i = 1; i<=4; i++)
    {
        int moveDir = priority[Idx][nowDir][i];
        
        int ny = y + dy[moveDir];
        int nx = x + dx[moveDir];

        if(ny < 0 || nx < 0 || ny >= N || nx >= N)
            continue;
        if(smell[ny][nx].second != Idx)
            continue;
        
        shark[Idx][0] = ny;
        shark[Idx][1] = nx;
        shark[Idx][2] = moveDir;

        return;
    }
}


int main()
{
    
    cin >> N >> M >> k;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            cin >> mp[y][x];

            if(mp[y][x] != 0)
            {
                smell[y][x] = make_pair(k,mp[y][x]);
                shark[mp[y][x]][0] = y;
                shark[mp[y][x]][1] = x;
                sharkNum++;
            }
        }
    }

    for(int i = 1; i <= M; i++)
        cin >> shark[i][2];

    for(int i = 1; i <= M; i++)
    {
        for(int j = 1; j < 5; j++)
            cin >> priority[i][j][1] >> priority[i][j][2] >> priority[i][j][3] >> priority[i][j][4];
    }

    int ret = 0;

    while(true)
    {
        ret++;
        // MOVE and Erase
        memset(tmp, 0, sizeof(tmp));
        
        for(int i = 1; i <= M; i++)
        {
            if(shark[i][2] == 0) // 죽음
                continue;
            
            move(i, shark[i][2]);

            if(tmp[shark[i][0]][shark[i][1]] == 0)
                tmp[shark[i][0]][shark[i][1]] = i;
            else //죽어라
            {
                shark[i][2] = 0;
                sharkNum--;
            }
        }

        memcpy(mp, tmp, sizeof(mp));

        if(sharkNum == 1)
            break;

        // SMELL

        for(int y = 0; y < N; y++)
        {
            for(int x = 0; x < N; x++)
            {
                if(smell[y][x].first)
                    smell[y][x].first--;

                if(!smell[y][x].first)
                    smell[y][x].second = 0;
            }
        }

        for(int y = 0; y < N; y++)
        {
            for(int x = 0; x < N; x++)
            {
                if(mp[y][x] != 0)
                {
                    smell[y][x].first = k;
                    smell[y][x].second = mp[y][x];
                }
            }
        }

        if(ret >=1000)
        {
            cout << "-1";
            return 0;
        }
    }

    cout << ret;
}