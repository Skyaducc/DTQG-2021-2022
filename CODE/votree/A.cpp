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
const int MAXN = 70011;
int n , q;
vector<int> adj[MAXN];
int num[MAXN] , h[MAXN] , par[MAXN][19] , id[MAXN] , cnt , f[MAXN][19][2];
void dfs(int u , int pa)
{
	num[u] = ++cnt;
	for (int v : adj[u])
	{
		if(v == pa)	continue;
		h[v] = h[u] + 1;
		par[v][0] = u;
		foru (i , 1 , 18)	par[v][i] = par[par[v][i-1]][i-1];
		dfs(v , u);
	}
}
int Get(int l , int r , int x)
{
	int k = log2(r - l + 1);
	return (x) ? max(f[l][k][x] , f[r-(1<<k)+1][k][x]) : min(f[l][k][x] , f[r-(1<<k)+1][k][x]); 
}
int lca(int u , int v)
{
	if(h[u] < h[v])	swap(u , v);
	ford(j , 18 , 0)
	{
		if(h[par[u][j]] >= h[v])
		{
			u = par[u][j];
		}
	}
	if(u == v)	return u;
	ford(j , 18 , 0)
	{
		while(par[u][j] != par[v][j])
		{
			u = par[u][j];
			v = par[v][j];
		}
	}
	return par[u][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> q;
    foru (i , 1 , n - 1)
    {
    	int u , v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    h[1] = 1;
    dfs(1 , -1);
    foru (i , 1 , n)
    {
    	id[num[i]] = i;
    	f[i][0][0] = f[i][0][1] = num[i];
    }
    foru (j , 1 , 18)
    {
    	foru (i , 1 , n - (1 << j) + 1)
    	{
    		f[i][j][0] = min(f[i][j-1][0] , f[i + (1 << (j - 1))][j-1][0]);
    		f[i][j][1] = max(f[i][j-1][1] , f[i + (1 << (j - 1))][j-1][1]);
    	}
    }
    while(q--)
    {
    	int x , y;
    	cin >> x >> y;
    	int u = Get(x , y , 0);
    	int v = Get(x , y , 1);
    	// cout << u << " " << v << " " << id[u] << " " << id[v] << endl;
    	cout << lca(id[u] , id[v]) << endl;
    }
    return 0;
}
