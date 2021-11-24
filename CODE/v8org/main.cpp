#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
using namespace std;
const int MAXN = 1e5 + 1;
int k , n , ans;
vector<int> adj[MAXN];
int visit[MAXN] , child[MAXN];
int dfs(int u)
{
    int sz = 1;
    for (int v : adj[u])
    {
        sz += dfs(v);
    }
    if(sz >= k)
    {
        ans++;
        sz = 0;
    }
    return sz;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> k >> n;
    for (int i=2 ; i<=n ; i++)
    {
        int u;
        cin >> u;
        adj[u].push_back(i);
    }
    dfs(1);
    cout << ans;
    return 0;
}
