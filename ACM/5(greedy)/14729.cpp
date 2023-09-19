#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;

    cin >> N;
    
    priority_queue<float> pq;
    priority_queue<float, vector<float>, greater<float>> pqRes;

    for(int i = 0; i < N; i++)
    {
        float s;

        cin >> s;

        if(pq.size() == 7)
        {
            if(pq.top() > s)
            {
                pq.pop();
                pq.push(s);
            }
        }
        else
        {
            pq.push(s);
        }
    }

    for(int i = 0; i < 7; i++)
    {
        pqRes.push(pq.top());
        pq.pop();
    }

    for(int i = 0; i<7; i++)
    {
        printf("%.3f\n", pqRes.top());
        pqRes.pop();
    }
}