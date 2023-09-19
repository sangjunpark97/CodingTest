#include <bits/stdc++.h>

using namespace std;

vector<deque<int>> vDq;
int mp[1001];

int main()
{
    int N;

    cin >> N;

    vDq.resize(1);

    for(int i = 0; i < N; i++)
    {
        deque<int> dq;
        
        for(int k = 0; k < 8; k++)
        {
            int a;

            scanf("%1d", &a);
            dq.push_back(a);   
        }

        vDq.push_back(dq);
    }

    int K;

    cin >> K;

    for(int i = 0; i < K; i++)
    {
        memset(mp, 0, sizeof(mp));

        int a, b;

        cin >> a >> b;

        mp[a] = b;

        for(int j = a - 1; j >= 1; j--)
        {
            if((vDq[j + 1][6] ^ vDq[j][2]) == 1)
            {
                if(mp[j + 1] == 1)
                    mp[j] = -1;
                else if(mp[j + 1] == -1)
                    mp[j] = 1;
            }
            else
                break;
        }

        for(int j = a + 1; j <= N; j++)
        {
            if((vDq[j - 1][2] ^ vDq[j][6]) == 1)
            {
                if(mp[j - 1] == 1)
                    mp[j] = -1;
                else if(mp[j - 1] == -1)
                    mp[j] = 1;
            }
            else
                break;
        }

        for(int i = 1; i <= N; i++)
        {
            if(mp[i] == 1)
            {
                int c = vDq[i].back();
                vDq[i].pop_back();
                vDq[i].push_front(c);
            }
            else if(mp[i] == -1)
            {
                int c = vDq[i].front();
                vDq[i].pop_front();
                vDq[i].push_back(c);
            }
        }
    }

    int ret = 0;

    for(int i = 1; i <= N; i++)
    {
        if(vDq[i][0] == 1)
            ret++;
    }

    cout << ret;
}