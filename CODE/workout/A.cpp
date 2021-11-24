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
vector<pii> adj[MAXN];
int d[MAXN] , dist[MAXN] , res[MAXN];
int u1 , v1;
struct Person
{
	int p , u , v;
} a[MAXN];
void dijkstra(int u)
{
	memset(d , 0x3f , sizeof(d));
	d[u] = 0;
	priority_queue<pii , vector<pii> , greater<pii> > pq;
	pq.push({0 , u});
	while(pq.size())
	{
		int u = pq.top().se;
		int du = pq.top().fi;
		pq.pop();
		if(du != d[u])	continue;
		for (pii h : adj[u])
		{
			int v = h.fi;
			int uv = h.se;
			if(d[v] > d[u] + uv)
			{
				d[v] = d[u] + uv;
				pq.push({d[v] , v});
			}
		}
	}
}
void dijkstra1(int u)
{
	memset(dist , 0x3f , sizeof(dist))
	dist[u] = 1;
	priority_queue<pii , vector<pii> , greater<pii>> pq;
	pq.push({0 , u});
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
			if(dist[v] > dist[u] + uv)
			{
				dist[v] = dist[u] + uv;
				if(a[1].p == 0)
				{
					if(dist[v] == d[v])	res[v] = max(res[v] , res[u] + uv);
					else	res[v] = res[u];
				}
				else
				{
					 	
				}
				pq.push({dist[v] , v});
			}
		}
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
    foru (i , 1 , m)
    {
    	int u , v , c;
    	cin >> u >> v >> c;
    	adj[u].push_back({v , c});
    	adj[v].push_back({u , c});
    }
    cin >> u1 >> v1;
    foru (i , 1 , k - 1)
    {
    	int p , u , v;
    	cin >> p >> u >> v;
    	a[i] = {p , u , v};
    }
    if(k == 2)
    {
    	dijkstra(u1);
    	cout << d[v1];
    	dijkstra1(a[1].u);
    }
    return 0;
}
