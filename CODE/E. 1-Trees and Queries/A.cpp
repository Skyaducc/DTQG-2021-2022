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
const int MAXN = 1e5 + 1;
const int LOGN = 20;
int n , q;
vector<int> adj[MAXN];
int h[MAXN];
int par[MAXN][LOGN + 1] , dist[MAXN][LOGN + 1];
void dfs(int u)
{
	for (int v : adj[u])
	{
		if(par[u][0] == v)	continue;
		par[v][0] = u;
		dist[v][0] = 1;
		h[v] = h[u] + 1;
		dfs(v);
	}
}
void init()
{
	foru (j , 1 , LOGN)
	{
		foru (i , 1 , n)
		{
			par[i][j] = par[par[i][j-1]][j-1];
		}
	}
	foru (j , 1 , LOGN)
	{
		foru (i , 1 , n)
		{
			dist[i][j] = dist[i][j-1] + dist[par[i][j-1]][j-1];
		}
	}
}
int lca(int u , int v)
{
	if(h[u] < h[v])	swap(u , v);
	int ans = 0;
	ford (j , LOGN , 0)
	{
		if(h[par[u][j]] >= h[v])
		{
			ans += dist[u][j];
			u = par[u][j];
		}
	}
	if(u == v)	return ans;
	ford (j , LOGN , 0)
	{
		while(par[u][j] != par[v][j])
		{
			ans += dist[u][j];
			ans += dist[v][j];
			u = par[u][j];
			v = par[v][j];
		}
	}
	return ans + dist[u][0] + dist[v][0];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n - 1)
    {
    	int u , v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    h[1] = 1;
    dfs(1);
    init();
    cin >> q;
    while(q--)
    {
    	int x , y , a , b , k;
    	cin >> x >> y >> a >> b >> k;
    	int tmp1 = lca(a , x);
    	int tmp2 = lca(b , y);
    	int tmp11 = lca(a , y);
    	int tmp22 = lca(b , x);
    	int tmp3 = lca(a , b);
    	int tmp4 = min(tmp1 + tmp2 , tmp11 + tmp22) + 1;
    	if(tmp3 % 2 == k % 2 && tmp3 <= k)
    	{
    		cout << "YES" << endl;
    		continue;
    	}
    	if(tmp4 % 2 == k % 2 && tmp4 <= k)
    	{
    		cout << "YES" << endl;
    		continue;
    	}
    	cout << "NO" << endl;
    }
    return 0;
}
