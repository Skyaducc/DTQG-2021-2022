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
const int MAXN = 1e5 + 11;
int n , k;
vector<int> adj[MAXN];
int a[MAXN] , h[MAXN] , Maxh[MAXN];
int d[MAXN] , deg[MAXN];
int Left , Right , res;
void DFS(int u , int par)
{
    for (int v : adj[u])
    {
        if(v == par)    continue;
        h[v] = h[u] + 1;
        DFS(v , u);
    }
    if(deg[u] == 1) Maxh[u] = h[u];
    for (int v : adj[u])
    {
        Maxh[u] = max(Maxh[u] , Maxh[v]);
    }
}
bool cmp(int x , int y)
{
    return Maxh[x] > Maxh[y];
}
void dfs(int u , int par)
{
    sort(adj[u].begin() , adj[u].end() , cmp);
	for (int v : adj[u])
	{
		if(v == par)	continue;
		dfs(v , u);
	}
	bool ok = true;
	for (int v : adj[u])
	{
		if(v == par)	continue;
		if(deg[v] != 1)	ok = false;
	}
	if(deg[u] == 1)		return;
	if(ok)
	{
		foru (i , 0 , (int)adj[u].size() - 3)
		{
			res += a[Left];
			Left++;
		}
		res += a[Right];
		d[u] = a[Right];
		Right--;
		cout << u << " " << res << endl;
	}
	else
	{
		int ma = 0;
		for (int v : adj[u])
		{
			if(adj[v].size() == 1)
			{
				res += a[Right];
				Right--;
				continue;
			}
			if(v == par)	continue;
			if(d[v])
			{
				ma = max(ma , d[v]);
			}
			else
			{
				res += a[Left];
				Left++;
			}
		}
		res += ma;
		d[u] = ma;
	}
}
int main()
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
    	cout << x << " " << i << endl;
    }
    sort(a + 1 , a + 1 + k);
    Left = 1 , Right = k;
    h[0] = 1;
    DFS(0 , -1);
    dfs(0 , -1);
    cout << res;
    return 0;
}
