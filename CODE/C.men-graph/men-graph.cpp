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
const int MOD = 998244353;
const int MAXN = 2011;
const int MAXM = 3e5 + 1;
int n , m;
vector<int> adj[MAXN];
int fact[MAXN];
pii a[MAXM];
void init()
{
	fact[0] = 1;
	foru (i , 1 , MAXN)
	{
		fact[i] = (fact[i-1] * i) % MOD;
	}
}
int ckn(int k, int n) 
{
    return  fact[n] / (fact[k] * fact[n-k]) % MOD;
}
int cnt1[MAXN] , cnt2[MAXN] , mark[MAXN][MAXN];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("men-graph.inp" , "r" , stdin);
    freopen("men-graph.out" , "w" , stdout);
    init();
    cin >> n >> m;
    foru (i , 1 , m)
    {
    	int u , v;
    	cin >> u >> v;
    	a[i] = {u , v};
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    foru (i , 1 , m)
    {
    	int u = a[i].fi , v = a[i].se;
    	cnt1[u] = adj[u].size() , cnt2[v] = adj[v].size();
    	for (int x : adj[u])
    	{
    		for (int y : adj[v])
    		{
    			if(x == v || y == u)	continue;
    			if(x == y) mark[u][v]++;
    		}
    	}
    }
    int res = 0;
    foru (i , 1 , m)
    {
    	int u = a[i].fi , v = a[i].se;
    	int tmp1 = (cnt1[u] > cnt2[v]) ? cnt1[u] - mark[u][v] : cnt1[u];
    	int tmp2 = (cnt1[u] <= cnt2[v]) ? cnt2[v] - mark[u][v] : cnt2[v];
    	if(tmp1 >= 4 && tmp2 >= 3)
    	{
    		res = (res + (ckn(3 , tmp1 - 1) * ckn(2 , tmp2 - 1)) % MOD) % MOD;
    	}
    	tmp1 = (cnt1[u] <= cnt2[v]) ? cnt1[u] : cnt1[u] - mark[u][v];
    	tmp2 = (cnt1[u] > cnt2[v]) ? cnt2[v] : cnt2[v] - mark[u][v];
    	if(tmp1 >= 3 && tmp2 >= 4)
    	{
    		res = (res + (ckn(2 , tmp1 - 1) * ckn(3 , tmp2 - 1)) % MOD) % MOD;
    	}
    }
    cout << res;
    return 0;
}
