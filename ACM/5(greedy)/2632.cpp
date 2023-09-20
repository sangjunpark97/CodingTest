#include <bits/stdc++.h>

using namespace std;

int A[1005], B[1005];
int psum_A[2005], psum_B[2005];

map<int, int> mA;
map<int, int> mB;

int main()
{
    int N;

    cin >> N;

    int a, b;

    cin >> a >> b;

    for(int i = 1; i <= a; i++)
    {
        cin >> A[i]; 
        psum_A[i] = psum_A[i - 1] + A[i];
    }

    for(int i = a + 1; i <= a * 2; i++)
        psum_A[i] = psum_A[i - 1] + A[i - a];


    for(int i = 1; i <= b; i++)
    {
        cin >> B[i];
        psum_B[i] = psum_B[i - 1] + B[i];
    }

    for(int i = b + 1; i <= b * 2; i++)
        psum_B[i] = psum_B[i - 1] + B[i - b];

    for(int interval = 1; interval <= a; interval++)
    {
        for(int i = 0; i < a; i++)
        {
            mA[psum_A[i + interval] - psum_A[i]]++;

            if(interval == a)
                break;
        }
    }


    for(int interval = 1; interval <= b; interval++)
    {
        for(int i = 0; i < b; i++)
        {
            mB[psum_B[i + interval] - psum_B[i]]++;

            if(interval == b)
                break;
        }
    }

    int ret = mB[N] + mA[N];

    for(int i = 1; i < N; i++)
    {
        ret += mA[i] * mB[N - i];
    }

    cout << ret;
}
