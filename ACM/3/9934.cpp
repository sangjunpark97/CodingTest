#include <bits/stdc++.h>
using namespace std;

vector<int> vctI;

struct node
{
    int num = 0;
    node* left = nullptr;
    node* right = nullptr;
};

    node nd[1024];
    int n;
    int cnt;
    queue<node*> que;
    int levelcnt;

void visit(node* pNode)
{
    //cout << pNode->num << " " << n << "\n";
    
    if(pNode->num * 2 + 1 >= n)
        return;

    pNode->left = &nd[pNode->num * 2 + 1];
    pNode->left->num = pNode->num * 2 + 1;
    pNode->right = &nd[pNode->num * 2 + 2];
    pNode->right->num = pNode->num * 2 + 2;

    visit(pNode->left); 
    visit(pNode->right);
}

void postorder(node* pNode)
{
    if(pNode->left) postorder(pNode->left);
    pNode->num = vctI[cnt++];
    if(pNode->right) postorder(pNode->right);
}

void BFS()
{
    while(que.size())
    {
        node* pNow = que.front();

        que.pop();

        cnt++;
        
        if(cnt == 2 || cnt == 4 || cnt == 8 || cnt == 16 || cnt == 32 || cnt == 64 || cnt == 128 || cnt == 256 || cnt == 512)
            cout << "\n";

        cout << pNow->num << " ";

        if(pNow->left)
        que.push(pNow->left);
        
        if(pNow->right)
        que.push(pNow->right);
    }
}

int main()
{

    int k;

    cin >> k;

    n = pow(2, k) - 1;

    for(int i = 0; i< n; i++)
    {
        int num;

        cin >> num;

        vctI.push_back(num);
    }

    nd[0].num = 0;
    visit(&nd[0]);

    cnt = 0;
    postorder(&nd[0]);
    que.push(&nd[0]);
    cnt = 0;
    BFS();
}