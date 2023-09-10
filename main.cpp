    #include <bits/stdc++.h>

    using namespace std;

    int T,W;
    int dp[1004][2][34];
    int table[1004];

    int go(int idx, int tree, int cnt)
    {
        if(idx == T)
            return 0;
        
        if(cnt > W)
            return -1e9;

        int &ret = dp[idx][tree][cnt];

        if(~ret)
            return ret;
        
        return ret = max(go(idx + 1, tree ^ 1, cnt + 1), go(idx + 1, tree, cnt)) + (tree == (table[idx] - 1));
    }

    int main()
    {
        cin >> T >> W;

        for(int i =0; i < T; i++)
            cin >> table[i];

        memset(dp, -1, sizeof(dp));

        cout << max(go(0, 0, 0),go(0,1,1));

        return 0;
    }

