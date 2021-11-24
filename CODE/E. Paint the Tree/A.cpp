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
const int MAXN = 5e5 + 1;
int q , n , k;
vector<pii> adj[MAXN];
int visited[MAXN];
int dp[MAXN][2]; // dp(i , j) : tổng trọng số các cạnh đc chọn và j = 0 là ko chọn cạnh từ đỉnh j -> cha nó
int res = 0;
void dfs(int u)
{
	visited[u] = 1;
	vector<int> ve;
	int sum = 0;
	for (pii h : adj[u])
	{
		int v = h.fi;
		int w = h.se;
		if(visited[v])	continue;
		dfs(v);
		sum += dp[v][0];
		ve.push_back(dp[v][1] + w - dp[v][0]);
	}
	sort(ve.begin() , ve.end() , greater<int>());
	foru (i , 0 , min((int)ve.size() , k) - 1)
	{
		if(ve[i] > 0)
		{
			sum += ve[i];
		}
	}
	dp[u][0] = dp[u][1] = sum;
	if(k <= (int)ve.size() && ve[k-1] > 0)
	{
		dp[u][1] -= ve[k-1];
	}
}
void Reset()
{
	foru (i , 1 , n)	
	{
		adj[i].clear();
		visited[i] = 0;
	}
}
void solve()
{
	cin >> n >> k;
	Reset();
	foru (i , 1 , n - 1)
	{
		int u , v , w;
		cin >> u >> v >> w;
		adj[u].push_back({v , w});
		adj[v].push_back({u , w});
	}
	dfs(1);
	cout << dp[1][0] << endl;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> q;
    while(q--)
    {
    	solve();
    }
    return 0;
}
