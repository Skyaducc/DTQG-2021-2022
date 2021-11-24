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
const int MAXN = 4e5 + 1;
int n , k , test;
vector<int> adj[MAXN];
int f[MAXN] , deg[MAXN] , cnt[MAXN];
void bfs()
{
	queue<int> qu;
	foru (i , 1 , n)	
	{
		if(deg[i] == 1)
		{
			qu.push(i);
			f[i] = 1;
		}
	}
	while(qu.size())
	{
		int u = qu.front();
		qu.pop();
		for (int v : adj[u])
		{
			if(--deg[v] == 1)
			{
				qu.push(v);
				f[v] = min(f[v] , f[u] + 1);
			}
		}
	}
}
void solve()
{
	cin >> n >> k;
	foru (i , 1 , n) 
	{
		adj[i].clear();
		deg[i] = 0;
		f[i] = n + 1;
		cnt[i] = 0;
	}
	foru (i , 1 , n - 1)
	{
		int u , v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	bfs();
	foru (i , 1 , n)	cnt[f[i]]++;
	int ans = n;
	foru (i , 1 , k)	
	{
		if(ans == 2 || ans == 1)
		{
			cout << 0 << endl;
			return;
		}
		ans -= cnt[i];
	}
	cout << ans << endl;		
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}