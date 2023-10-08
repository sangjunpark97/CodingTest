#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int visited[5001];
vector<pair<int,int>> vec[5001];
int N, Q;

int DFS(int v, int k, int usado)
{
    int ret = 0;

    visited[v] = 1;

    for(int i = 0; i < vec[v].size(); i++)
    {
        if(visited[vec[v][i].first])
            continue;
        else
        {
            int newUsa = min(vec[v][i].second, usado);

            if(newUsa >= k)
                ret += DFS(vec[v][i].first, k, newUsa) + 1;
            else
                ret += DFS(vec[v][i].first, k, newUsa);
        }
    }

    return ret;
}

int main()
{
    fastio;
    cin >> N >> Q;

    for(int i = 1; i < N; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;

        vec[a].push_back(make_pair(b,c));
        vec[b].push_back(make_pair(a,c));
    }

    for(int i = 0; i < Q; i++)
    {
        memset(visited, 0, sizeof(visited));
        int k, v;

        cin >> k >> v;

        int ret = DFS(v,k, 2000000000);

        cout << ret << "\n";
    }
}