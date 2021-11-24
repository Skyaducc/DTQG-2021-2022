#include <iostream>
#include <bits/stdc++.h>
#define FORU(i , a , b) for (int i = (a) ; i <= (b) ; i++)
#define FORD(i , a , b) for (int i = (a) ; i >= (b) ; i--)
#define pii pair <int , int>
#define fi first
#define se second
#define oo (int)1e9
#define getbit(i , x) ((x >> i) & 1)
#define task ""
using namespace std;
const int maxn = 2e5 + 10;
vector <int> adj[maxn] , Directed[maxn];
bool dd[maxn] , mark[maxn];
int dp[maxn] , par[maxn] , u0 , v0 , n;
int d[maxn] , d1[maxn] , child[maxn];
void dfs(int u)
{
    dd[u] = 1;
    for (int v : adj[u])
    {
        if (!dd[v])
        {
            par[v] = u;
            Directed[u].push_back(v);
            dfs(v);
        }
    }
}
void init()
{
    dfs(u0);
    int v = v0;
    while (v != 0)
    {
        mark[v] = 1;
        if (par[v] != 0) child[par[v]] = v;
        v = par[v];
    }
}
void DFS(int u)
{
    dp[u] = 1;
    for (int v : Directed[u])
    {
        if (!mark[v])
        {
            DFS(v);
            dp[u] = max(dp[u] , dp[v] + 1);
        }
    }
}
void solve()
{
    cin >> n;
    FORU(i , 1 , n - 1)
    {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> u0 >> v0;
    init();
    int j = 0 , v = v0;
    v = u0;
    while (v != 0)
    {
        DFS(v);
        d[v] = max(d[par[v]] , j + dp[v]);
        v = child[v]; j++;
    }
    for (int i=1 ; i<=n ; i++)
    {
    	cout << dp[i] << " ";
    }
    cout << endl;
    v = v0; j = 0;
    while (v != 0)
    {
        d1[v] = max(d1[child[v]] , j + dp[v]);
        v = par[v]; j++;
    }
    int ret = 0;
    v = u0;
    while (child[v] != 0)
    {
    	cout << d[v] << " " << d1[child[v]] << endl;
        ret = max(ret , min(d[v] , d1[child[v]]));
        v = child[v];
    }
    cout << ret;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("x.inp" , "r" , stdin);
    solve();
    //cout << "\n" << mark[5];
    return 0;
}