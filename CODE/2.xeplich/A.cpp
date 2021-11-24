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
const int MAXN = 1e5 + 11;
int n , k;
vector<int> adj[MAXN];
int a[MAXN];
int h[MAXN] , MaxH[MAXN] , deg[MAXN];
int res;
vector<int> ve;
void dfs(int u , int par)
{
	for (int v : adj[u])
	{
		if (v == par)	continue;
		h[v] = h[u] + 1;
		dfs(v , u);
	}
	bool ok = true;
	for (int v : adj[u])
	{
		if(v == par)	continue;
		if(deg[v] != 1)	ok = false;
	}
	if(ok && deg[u] != 1)
	{
		MaxH[u] = h[u] + 1;
	}
	else if(deg[u] != 1)
	{
		int ma = 0 , ver;
		for (int v : adj[u])
		{
			if(v == par)	continue;
			if(ma < MaxH[v])
			{
				ma = MaxH[v];
				ver = v;
			}
		}
		for (int v : adj[u])
		{
			if(v == par)	continue;
			if(MaxH[v] != 0 && MaxH[v] < ma)	
			{
				ve.push_back(MaxH[v] - h[u]);
			}
			if(MaxH[v] == ma && ver != v)	ve.push_back(MaxH[v] - h[u]);
		}
		MaxH[u] = ma;
	}
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k;
    foru (i , 1 , k)	cin >> a[i];
    foru (i , 1 , n - 1)
    {
    	int x;
    	cin >> x;
    	adj[i].push_back(x);
    	adj[x].push_back(i);
    	deg[i]++;
    	deg[x]++;
    	// cout << x << " " << i << endl;
    }
    sort(a + 1 , a + 1 + k);
    h[0] = 1;
    dfs(0 , -1);
    int tmp = k;
    ve.push_back(MaxH[0] - 1);
    sort(ve.begin() , ve.end() , greater<int>());
    for (int x : ve)
    {
    	res += a[tmp] * x;
    	// cout << a[tmp] << " " << x << endl;
    	tmp--;
    }
    // cout << res << endl;
    ford (i , tmp , 1)	res += a[i];
    cout << res;
    return 0;
}