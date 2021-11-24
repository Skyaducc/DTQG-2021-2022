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
int n , m , k;
int color[MAXN];
pii edge[MAXN];
int dp[MAXN][33];
void solve1(int mask)
{
	foru (i , 1 , m)
	{
		int u = edge[i].fi , v = edge[i].se;
		if(color[u] == color[v])	continue; 
		if(BIT(mask , color[u]) == 1)
		{
			int prev = SET_OFF(mask , color[u]);
			dp[u][mask] += dp[v][prev];
		}
	}
	int res = 0;
	foru (i , 1 , m)
	{
		int u = edge[i].fi , v = edge[i].se;
		if(color[u] == color[v])	continue;
		res += dp[u][mask];
	}
}
void solve2(int mask)
{
	foru (i , 1 , m)
	{
		int u = edge[i].fi , v = edge[i].se;
		if(color[u] == color[v])	continue; 
		if(BIT(mask , color[v]) == 1)
		{
			int prev = SET_OFF(mask , color[v]);
			dp[v][mask] += dp[u][prev];
		}
	}
	int res = 0;
	foru (i , 1 , m)
	{
		int u = edge[i].fi , v = edge[i].se;
		if(color[u] == color[v])	continue;
		res += dp[v][mask];
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m >> k;
    foru (i , 1 , n)
    {
    	cin >> color[i];
    	color[i]--;
    }
    foru (i , 1 , m)
    {
    	int u , v;
    	cin >> u >> v;
    	edge[i] = {u , v};
    }
    foru (i , 1 , m)
	{
		int u = edge[i].fi , v = edge[i].se;
		if(color[u] == color[v])	continue;
		dp[u][(1 << color[u])] = 1;
		dp[v][(1 << color[v])] = 1;
	}
    int last = (1 << k);
    long long res = 0;
    foru (mask , 1 , last - 1)
    {
    	solve1(mask);
    	solve2(mask);	
    	int k = __builtin_popcount(mask);
    	if(k < 2)	continue;
    	foru (i , 1 , n)
    	{
    		res += dp[i][mask];
    	}
    }
    cout << res;
    return 0;
}
