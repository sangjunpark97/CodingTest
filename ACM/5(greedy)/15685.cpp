#include <bits/stdc++.h>

using namespace std;

int mp[101][101];


int main()
{
    int N;

    cin >> N;

    vector<int> move;

    for(int i = 0; i < N; i++)
    {
        move.clear();

        int x, y, d, g;

        cin >> x >> y >> d >> g;

        mp[y][x] = 1;

        if(d == 0)
            mp[y][++x] = 1;
        if(d == 1)
            mp[--y][x] = 1;
        if(d == 2)
            mp[y][--x] = 1;
        if(d == 3)
            mp[++y][x] = 1;
        
        move.push_back(d);

        g--;

        while(g >= 0)
        {
            for(int j = move.size() - 1; j >= 0; j--)
            {
                int dir = (move[j] + 1) % 4;

                if(dir == 0)
                    mp[y][++x] = 1;
                if(dir == 1)
                    mp[--y][x] = 1;
                if(dir == 2)
                    mp[y][--x] = 1;
                if(dir == 3)
                    mp[++y][x] = 1;

                move.push_back(dir);
            }

            g--;
        }
    }

    int ret = 0;

    for(int y = 0; y < 100; y++)
    {
        for(int x = 0; x < 100; x++)
        {
            if(mp[y][x] && mp[y+1][x] && mp[y][x+1] && mp[y+1][x+1])
                ret++;
        }
    }
    
    cout << ret;
}