#include <bits/stdc++.h>
using namespace std;

int mp[30][9];
int N, M, H;
int ret = 987654321;

bool check()
{
    int A[10] = {1,2,3,4,5,6,7,8,9,10};

    for(int i = 0; i< H; i++)
    {
        for(int j = 0; j < N - 1; j++)
        {
            if(mp[i][j])
            {
                int tmp = A[j];

                A[j] = A[j+1];
                A[j+ 1] = tmp; 
            }
        }
    }

    bool bReturn = true;

    for(int i = 0; i < N; i++)
    {
        if(A[i]!= i + 1)
            bReturn = false;
    }

    return bReturn;
}

void go(int a, int b, int cnt)
{
    if(ret < cnt)
        return;

    //cout << a << " " << b << endl;

    if(check())
    {
        if(ret > cnt)
            ret = cnt;
    }

    if(cnt <3)
    {
        for(int i = a; i < H; i++)
        {
            if(i != a)
                b = -1;

            for(int j = b + 1; j < N -1; j++)
            {
                if(j +1 < N-1 && mp[i][j+1] == 1)
                    continue;

                if(j -1 >= 0 && mp[i][j-1] == 1)
                    continue;

                if(mp[i][j])
                    continue;
                    
                mp[i][j] = 1;
                go(i, j, cnt+1);
                mp[i][j] = 0;
            }
        }
    }
}

int main()
{
    cin >> N >> M >> H;

    for(int i = 0; i< M; ++i)
    {
        int a, b;

        cin >> a >> b;

        mp[a - 1][b - 1] = 1;
    }
    
    go(0,-1,0);

    if(ret > 3)
        cout << "-1";
    else
        cout << ret;
}