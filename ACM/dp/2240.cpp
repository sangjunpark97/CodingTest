#include <bits/stdc++.h>

using namespace std;

int mp[1004][34][2];
int table[1004];
int T, W;

int go(int idx, int tree, int cnt)
{
    if(cnt < 0)
        return -1e9;
    
    if(idx == T)
    {
        if(cnt == 0)
            return 0;
        else
            return -1e9;
    }
    
    if(mp[idx][cnt][tree] != -1)
        return mp[idx][cnt][tree];

    mp[idx][cnt][tree] = max(go(idx + 1, tree ^1, cnt -1), go(idx + 1, tree, cnt)) + (tree + 1 == table[idx]);

    return mp[idx][cnt][tree];
}

int main()
{
    memset(mp, -1, sizeof(mp));
    cin >> T >> W;

    for(int i = 0; i < T; i++)
    {
        cin >> table[i];
    }

    int ret = max(go(0,0,W), go(0, 1, W -1));

    cout << ret;
}