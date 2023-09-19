#include <bits/stdc++.h>

using namespace std;

int mp[51][51];
int org[51][51];
int tmp[51][51];

int main()
{
    int N, M;

    cin >> N >> M;

    int k;

    cin >> k;

    for(int y = 1; y <= N; y++)
    {
        for(int x = 1; x <= M; x++)
        {
            cin >> mp[y][x];
        }
    }

    vector<int> v;

    for(int i = 0; i < k; i++)
        v.push_back(i);

    vector<vector<int>> table;

    for(int i = 0; i < k; i++)
    {
        int r, c, s;

        cin >> r >> c >> s;

        vector<int> a;

        a.push_back(r);
        a.push_back(c);
        a.push_back(s);

        table.push_back(a);
    }

    memcpy(org, mp, sizeof(mp));

    int ret = 987654321;

    do
    {
        memcpy(mp, org, sizeof(mp));

        for(auto i : v)
        {
            int r = table[i][0];
            int c = table[i][1];
            int s = table[i][2];

            memcpy(tmp, mp, sizeof(mp));

            while(s)
            {
                for(int y = r -s; y <= r + s; y++)
                {
                    for(int x = c - s; x <= c +s; x++)
                    {
                        if(y == r - s && x == c - s)
                            tmp[y][x] = mp[y + 1][x];
                        else if(y == r - s && x == c + s)
                            tmp[y][x] = mp[y][x - 1];
                        else if(y == r + s && x == c - s)
                            tmp[y][x] = mp[y][x + 1];
                        else if(y == r + s && x == c + s)
                            tmp[y][x] = mp[y - 1][x];
                        else if(y == r - s)
                            tmp[y][x] = mp[y][x - 1];
                        else if(y == r + s)
                            tmp[y][x] = mp[y][x + 1];
                        else if(x == c - s)
                            tmp[y][x] = mp[y + 1][x];
                        else if(x == c + s)
                            tmp[y][x] = mp[y - 1][x];
                    }
                }
                
                s--;
            }

            memcpy(mp, tmp, sizeof(mp));
        }

        for(int y = 1; y <= N; y++)
        {
            int cnt = 0;

            for(int x = 1; x <= M; x++)
            {
                cnt += mp[y][x];
            }

            ret = min(cnt, ret);
        }
    } while (next_permutation(v.begin(), v.end()));

    cout << ret;
}