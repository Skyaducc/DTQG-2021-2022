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
const int MAXN = 1e4 + 1;
const int LOGN = 20;
int n , q;
vector<pii> adj[MAXN];
int par[MAXN][LOGN+1] , d[MAXN][LOGN+1];
int h[MAXN] , Visit[MAXN];
void dfs(int u)
{
    Visit[u] = 1;
    for(pii x : adj[u])
    {
        int v = x.fi;
        int w = x.se;
        if(Visit[v]) continue;
        h[v] = h[u] + 1;
        par[v][0] = u;
        d[v][0] = w;
        dfs(v);
    }
}
void init()
{
    for (int j=1 ; j<=LOGN ; j++)
    {
        for (int i=1 ; i<=n ; i++)
        {
            par[i][j] = par[par[i][j-1]][j-1];
        }
    }
    for (int j=1 ; j<=LOGN ; j++)
    {
        for (int i=1 ; i<=n ; i++)
        {
            d[i][j] = d[i][j-1] + d[par[i][j-1]][j-1];
        }
    }
}
int lca(int u , int v)
{
    if(u == v)  return 0;
    int ans = 0;
    if(h[u] < h[v]) swap(u , v);
    for (int j=LOGN ; j>=0 ; j--)
    {
        if(h[par[u][j]] >= h[v])
        {
            ans += d[u][j];
            u = par[u][j];
        }
    }
    if(u == v)  return ans;
    for (int j=LOGN ; j>=0 ; j--)
    {
        while(par[u][j] != par[v][j])
        {
            ans += d[u][j];
            ans += d[v][j];
            u = par[u][j];
            v = par[v][j];
        }
    }
    ans += d[u][0] + d[v][0];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> q;
    for (int i=1 ; i<=n-1 ; i++)
    {
        int u , v , c;
        cin >> u >> v >> c;
        adj[u].push_back({v , c});
        adj[v].push_back({u , c});
    }
    h[1] = 1;
    dfs(1);
    init();
    while(q--)
    {
        int u , v;
        cin >> u >> v;
        cout << lca(u , v) << endl;
    }
    return 0;
}
