#include <bits/stdc++.h>
using namespace std;

int N;
int ret = 987654321;
int pop[10];
int visited[10];
vector<int> vctI[10];
int cnt;

void go(int n, int t)
{
    visited[n] = 1;

    for(auto i : vctI[n])
    {
        if(visited[i] != t && visited[i] != 1)
            go(i, t);
    }
}

int main()
{
    int N;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> pop[i];
    }

    for(int i = 0; i< N; i++)
    {
        int K;

        cin >> K;

        for(int j = 0; j<K; j++)
        {
            int n;

            cin >> n;
            vctI[i].push_back(n - 1);
        }
    }

    for(int i = 0; i < pow(2,N); i++)
    {
        vector<int> A;
        vector<int> B;

        if(i == 0 || i == pow(2,N) - 1)
            continue;

        for(int j = 0; j < N; j++)
        {
            if(i & (1 << j))
            {
                A.push_back(j);
                visited[j] = -1;
            }
            else
            {
                B.push_back(j);
                visited[j] = -2;
            }
        }

        go(A[0], -2);
        go(B[0], -1);

        bool bOK = true;

        for(int t = 0; t < N; t++)
        {
            if(visited[t] != 1)
            {
                bOK = false;
                break;
            }
        }

        int sumA = 0;
        int sumB = 0;

        if(bOK)
        {
            for(auto a : A)
            {
                sumA += pop[a];
            }

            for(auto b : B)
            {
                sumB += pop[b];
            }

            if(abs(sumA - sumB) < ret)
            {
                ret = abs(sumA - sumB);
            }
            cnt++;
        }
    }


    if(cnt)
    cout << ret;
    else
    cout << "-1";
}