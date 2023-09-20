#include <bits/stdc++.h>

using namespace std;
vector<int> v;
int ret = -1;
int mp[4][100] = {{0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40},
                {0,2,4,6,8,10,13,16,19,25,30,35,40}, 
                {0,2,4,6,8,10,12,14,16,18,20,22,24,25,30,35,40},
                {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,28,27,26,25,30,35,40}};

void go(int now, int cnt, vector<pair<int,int>> unit)
{
    if(now == 10)
    {
        ret = max(ret, cnt);
    }
    else
    {
        for(int i = 0; i < 4; i++)
        {
            unit[i].first += v[now];

            int p = unit[i].second;

            if(unit[i].first == 5 && unit[i].second == 0)
                unit[i].second = 1;
            if(unit[i].first == 10 && unit[i].second == 0)
                unit[i].second = 2;
            if(unit[i].first == 15 && unit[i].second == 0)
                unit[i].second = 3;

            bool bCheck = false;

            for(int j = 0; j <4; j++)
            {
                if(i != j)
                {
                    int l = mp[unit[i].second][unit[i].first];
                    int r = mp[unit[j].second][unit[j].first];

                    if(l != 0 && l == r)
                    {
                        if(unit[i].second == unit[j].second)
                            bCheck = true;
                        else if(l == 40 || l == 35)
                            bCheck = true;
                        else if(l == 30)
                        {
                            if(unit[i].first == 15 && unit[j].first != 15)
                            {}
                            else if(unit[i].first != 15 && unit[j].first == 15)
                            {}
                            else
                                bCheck = true;
                        }
                    }
                }
            }

            if(bCheck == false)
                go(now + 1, cnt + mp[unit[i].second][unit[i].first], unit);

            unit[i].first -= v[now];
            unit[i].second = p;
        }
    }
}

int main()
{
    vector<pair<int,int>> unit;

    unit.push_back(pair<int,int>(0,0));
    unit.push_back(pair<int,int>(0,0));
    unit.push_back(pair<int,int>(0,0));
    unit.push_back(pair<int,int>(0,0));
    v.resize(10);

    for(int i = 0; i < 10; i++)
        cin >> v[i];

    go(0,0,unit);

    cout << ret;
}