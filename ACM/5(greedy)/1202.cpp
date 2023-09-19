#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long N, K;

    cin >> N >> K;

    vector<pair<long long,long long>> rock;
    vector<long long> bag;

    for(long long i = 0; i < N; i++)
    {
        long long m, v;

        cin >> m >> v;

        rock.push_back(pair<long long, long long>(m,v));
    }
    
    for(long long i =0; i <K; i++)
    {
        long long t;
        
        cin >> t;

        bag.push_back(t);
    }

    sort(rock.begin(), rock.end());
    sort(bag.begin(),bag.end());

    long long ret = 0;

    priority_queue<long long> pq;

    int j = 0;
    for(auto b : bag)
    {
        while(j < rock.size() && rock[j].first <= b)pq.push(rock[j++].second);
    }

    int i = 0;
    while(pq.size())
    {
        ret+=pq.top(); pq.pop();
        i++;

        if(i >= bag.size())
            break;
    }

    cout << ret;
}