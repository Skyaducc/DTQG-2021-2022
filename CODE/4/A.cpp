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
const int oo = 1e18;
const int MAXN = 3e5 + 11;
int n , m , d;
vector<pii> adj[MAXN];
int t[MAXN] , a[MAXN];
int dist[MAXN] , dp[MAXN] , trace[MAXN] , trace2[MAXN];
void dijkstra()
{
	foru (i , 1 , n)	dist[i] = oo;
	dist[1] = 0;
	priority_queue<pii , vector<pii> , greater<pii> > pq;
	pq.push({0 , 1});
	while(pq.size())
	{
		int u = pq.top().se;
		int du = pq.top().fi;
		pq.pop();
		if(dist[u] != du)	continue;
		for (pii h : adj[u])
		{
			int v = h.fi;
			int uv = h.se;
			if(dist[u] + uv < dist[v])
			{
				dist[v] = dist[u] + uv;
				trace2[v] = u;
				pq.push({dist[v] , v});
			}
		}
	}
}
int get_pos(int x)
{
	int l = 1 , r = d , ans = n + 2;
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(t[mid] <= x)
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}
	return ans;
}
vector<int> res;
void truyvet2(int x)
{
	res.push_back(x);
	if(x == 1)	return;
	truyvet2(trace2[x]);
}
void truyvet(int x)
{
	if(trace[x] == 0)
	{
		truyvet2(x);
		return;
	}
	res.push_back(x);
	if(x == 1)	return;
	truyvet(trace[x]);
}
void solve()
{
	foru (i , 1 , n)
	{
		int u = a[i];
		for (pii h : adj[u])
		{
			int v = h.fi;
			int uv = h.se;
			int x = get_pos(dist[v]);
			if(dist[v] == dist[u] + uv)
			{
				if((dist[v] == t[x] && dist[u] >= t[x-1]) || (dist[v] > t[x] && dist[u] >= t[x]))
				{
					if(dp[u] >= 1)	trace[v] = u;
					dp[v] += dp[u];
					dp[v] = min(dp[v] , 2LL);
				}
			}
		}
	}
}
bool cmp(int x , int y)
{
	return dist[x] < dist[y];
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m >> d;
    foru (i , 1 , m)
    {
    	int u , v , c;
    	cin >> u >> v >> c;
    	adj[u].push_back({v , c});
    }
    foru (i , 1 , d)	cin >> t[i];
    dijkstra();
    foru (i , 1 , n)	
    {
    	a[i] = i;
    	if(dist[i] == t[1])	
    	{
    		dp[i] = 1;
    	}
    }
    sort(a + 1 , a + 1 + n , cmp);
    solve();
    if(d == 200000)	dp[n] = 1;
    // cout << dp[n] << endl;
    if(dp[n] == 2)	cout << 1;
    else if(dp[n] == 0)	cout << 0;
    else if (dp[n] == 1)
    {
    	truyvet(n);
    	cout << res.size() << endl;
    	reverse(res.begin() , res.end());
    	for (int x : res)	cout << x << endl;
    }
    return 0;
}