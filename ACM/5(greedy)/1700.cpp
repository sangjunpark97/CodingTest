#include <bits/stdc++.h>

using namespace std;

int visited[101];

int main()
{
    int N, K;
    int ret = 0;

    cin >> K >> N;

    vector<int> now;
    vector<int> all;

    for(int i = 0; i < N; i++)
    {
        int n;
        
        cin >> n;

        all.push_back(n);
    }

    for(int i = 0; i < N; i++)
    {
        if(now.size() < K)
        {
            if(!visited[all[i]])
            {
                now.push_back(all[i]);
                visited[all[i]] = 1;
            }
        }
        else
        {
            if(visited[all[i]] == 0)
            {
                int swapN = -1;
                int cnt = -1;

                for(int j = 0; j < now.size(); j++)
                {
                    bool bCheck = false;

                    for(int k = i + 1; k < all.size(); k++)
                    {
                        if(now[j] == all[k])
                        {
                            bCheck = true;

                            if(cnt < k)
                            {
                                cnt = k;
                                swapN = j;
                            }
                            break;
                        }
                    }

                    if(bCheck == false)
                    {
                        swapN = j;
                        break;
                    }
                }

                ret++;

                visited[now[swapN]] = 0;
                visited[all[i]] = 1;
                
                now[swapN] = all[i];
            }
        }
    }

    cout << ret;
}