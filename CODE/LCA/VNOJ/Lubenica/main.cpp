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
const int LOGN = 20;
const int oo = 1e9;
int n , q;
vector<pii> adj[MAXN];
int par[MAXN][LOGN+1] , d[MAXN][LOGN+1][2];
int Visit[MAXN] , h[MAXN];
void dfs(int u)
{
    Visit[u] = 1;
    for (pii x : adj[u])
    {
        int v = x.fi , w = x.se;
        if(Visit[v])    continue;
        h[v] = h[u] + 1;
        par[v][0] = u;
        d[v][0][0] = d[v][0][1] = w;
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
            d[i][j][0] = max(d[i][j-1][0] , d[par[i][j-1]][j-1][0]);
            d[i][j][1] = min(d[i][j-1][1] , d[par[i][j-1]][j-1][1]);
        }
    }
}
int lca(int u , int v , int p)
{
    int ans1 = 0 , ans2 = oo;
    if(u == v)  return 0;
    if(h[u] < h[v]) swap(u , v);
    for (int j=LOGN ; j>=0 ; j--)
    {
        if(h[par[u][j]] >= h[v])
        {
            ans1 = max(ans1 , d[u][j][p]);
            ans2 = min(ans2 , d[u][j][p]);
            u = par[u][j];
        }
    }
    if(u == v)
    {
        if(p == 0)  return ans1;
        else    return ans2;
    }
    for (int j=LOGN ; j>=0 ; j--)
    {
        while(par[u][j] != par[v][j])
        {
            ans1 = max(ans1 , d[u][j][p]);
            ans1 = max(ans1 , d[v][j][p]);
            ans2 = min(ans2 , d[u][j][p]);
            ans2 = min(ans2 , d[v][j][p]);
            u = par[u][j];
            v = par[v][j];
        }
    }
    ans1 = max(ans1 , max(d[u][0][p] , d[v][0][p]));
    ans2 = min(ans2 , min(d[u][0][p] , d[v][0][p]));
    if(p == 0)  return ans1;
    else    return ans2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
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
    cin >> q;
    while(q--)
    {
        int u , v;
        cin >> u >> v;
        cout << lca(u , v , 1) << " " << lca(u , v , 0) << endl;
    }
    return 0;
}
