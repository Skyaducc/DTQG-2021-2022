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
using namespace std;
const int oo = 1e9;
const int MAXN = 2e5 + 1;
const int LOG = 20;
int n , m , k;
vector<int> adj[MAXN];
int a[MAXN] , h[MAXN];
int par[MAXN][LOG + 1];
void dfs(int u)
{
	for (int v : adj[u])
	{
		if(par[u][0] == v)	continue;
		par[v][0] = u;
		foru (i , 1 , LOG)	par[v][i] = par[par[v][i-1]][i-1];
		h[v] = h[u] + 1;
		dfs(v);
	}
}
int lca(int u , int v)
{
	if(h[u] < h[v])	swap(u , v);
	ford (j , LOG , 0)
	{
		if(h[par[u][j]] >= h[v])
		{
			u = par[u][j];
		}
	}
	if(u == v)	return u;
	ford (j , LOG , 0)
	{
		while(par[u][j] != par[v][j])
		{
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}
bool cmp(int a , int b)
{
	return h[a] < h[b];
}
bool check(int u , int v)
{
	int tmp = lca(u , v);
	return (u == tmp || v == tmp);
}
void solve()
{
	cin >> k;
	foru (i , 1 , k)	cin >> a[i];
	sort(a + 1 , a + 1 + k , cmp);
	foru (i , 1 , k)	a[i] = par[a[i]][0];
	foru (i , 1 , k - 1)
	{
		if(!check(a[i] , a[i+1]))
		{
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m;
    foru (i , 1 , n - 1)
    {
    	int u , v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    par[1][0] = 1;
    h[1] = 1;
    dfs(1);
    while(m--)
    {
    	solve();
    }
    return 0;
}
