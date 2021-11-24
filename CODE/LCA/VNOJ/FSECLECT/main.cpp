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
const int MAXN = 2e5 + 1;
const int LOGN = 18;
const int oo = 1e9;
int n , k , root;
vector<int> adj[MAXN];
vector<int> v[MAXN];
int Visit[MAXN] , h[MAXN];
int par[MAXN][LOGN+1] , d[MAXN][LOGN+1];
void dfs(int u)
{
    Visit[u] = 1;
    for (int v : adj[u])
    {
        if(Visit[v])   continue;
        h[v] = h[u] + 1;
        par[v][0] = u;
        d[v][0] = 1;
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
            d[i][j] = d[par[i][j-1]][j-1] + d[i][j-1];
        }
    }
}
int lca(int u , int v)
{
    int ans = 0;
    if(u == v)  return 0;
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
    cin >> n >> k;
    for (int i=1 ; i<=n ; i++)
    {
        int c , u;
        cin >> c >> u;
        v[c].push_back(i);
        if(u == 0)
        {
            root = i;
            continue;
        }
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    h[root] = 1;
    dfs(root);
    init();
    for (int i=1 ; i<=k ; i++)
    {
        int x = v[i][0];
        int tmp = 0 , dist = 0;
        for (int j=1 ; j<v[i].size() ; j++)
        {
            int y = v[i][j];
            int tmp1 = lca(x , y);
            if(tmp < tmp1)
            {
                tmp = tmp1;
                dist = y;
            }
        }
//        cout << x << " " << dist << endl;
        int ans = 0;
        for (int j=0 ; j<v[i].size() ; j++)
        {
            int y = v[i][j];
            ans = max(ans , lca(dist , y));
        }
        cout << ans << endl;
    }
    return 0;
}
