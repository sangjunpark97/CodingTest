#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N, M;
int T;
vector<int> A;
vector<int> B;

int main()
{
    cin >> T;

    vector<int> v;

    while(T--)
    {
        A.clear();
        B.clear();
        cin >> N >> M;

        for(int i = 0; i < N; i++)
        {
            int a;
            cin >> a;
            A.push_back(a);
        }
        
        for(int i = 0; i < M; i++)
        {
            int a;
            cin >> a;
            B.push_back(a);
        }

        sort(B.begin(), B.end());

        int ret = 0;

        for(int i = 0; i < A.size(); i++)
        {
            int pos = lower_bound(B.begin(), B.end(), A[i]) - B.begin();

            ret += pos;
        }

        v.push_back(ret);
    }

    for(auto i : v)
        cout << i << "\n";
}