#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl; 
#define int long long
using namespace std;
const int oo = 1e9;
const int MAXN = 2e5 + 111;
const int LOGN = 21;
int n;
struct Data
{
	int ver , c1 , c2;
};
vector<Data> adj[MAXN];
int cnt[MAXN];
int par[MAXN][LOGN + 1] , h[MAXN];
void dfs(int u)
{
    for (Data x : adj[u])
    {
    	int v = x.ver;
        if (v == par[u][0]) continue;
        par[v][0] = u;
        foru (j , 1 , 18)   par[v][j] = par[par[v][j-1]][j-1];
        h[v] = h[u] + 1;
        dfs(v);
    }
}
int lca(int u , int v)
{
    if (h[u] < h[v]) swap(u , v);
    int delta = h[u] - h[v];
    ford (i , LOGN , 0) if ((delta >> i) & 1) u = par[u][i];
    if (u == v) return u;
    ford (i , LOGN , 0)
    {
        while (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
void DFS(int u , int par)
{
	for (Data h : adj[u])
	{
		int v = h.ver;
		if(v == par)	continue;
		DFS(v , u);
		cnt[u] += cnt[v];
	}
}
int res = 0;
void DFS1(int u , int par)
{
	for (Data h : adj[u])
	{
		int v = h.ver;
		if(v == par)	continue;
		res += min((cnt[v]) * h.c1 , h.c2);
		// cout << v << " " << u << " " << cnt[v] << " " << cnt[u] << endl;
		DFS1(v , u);
	}
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n - 1)
    {
    	int u , v , c1 , c2;
    	cin >> u >> v >> c1 >> c2;
    	adj[u].push_back({v , c1 , c2});
    	adj[v].push_back({u , c1 , c2});
    }
    h[1] = 1;
    dfs(1);
    foru (i , 1 , n - 1)
    {
    	int u = lca(i , i + 1);
    	cnt[u] -= 2;
    	cnt[i]++;
    	cnt[i+1]++;
    }
    DFS(1 , -1);
    DFS1(1 , 0);
    cout << res;
    return 0;
}