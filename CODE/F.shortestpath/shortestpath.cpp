#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<long long,int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , b , a) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl; 
#define ll long long
using namespace std;
const ll oo = 1e18;
const int MAXN = 5 * 1e5 + 11;
ll n , m , p;
ll d[MAXN];
vector<pii> adj[MAXN];
vector<pii> fromarc[MAXN]; // danh sách cạnh vào đỉnh u
vector<pii> toarc[MAXN]; // danh sách cạnh ra đỉnh u 
vector<int> comps[MAXN]; // danh sách các đỉnh trong tplt i
int compid[MAXN]; // đỉnh u thuộc tplt nào
bool Inqueue[MAXN]; // inqueuq[u] = true khi u có trong hàng 
int numcomp , numtopo; // số tplt
int root[MAXN] , topo[MAXN]; // chứa các đỉnh theo thứ tự topo 
int deg[MAXN] , visited[MAXN];
set<int> s;
int get_root(int u)
{
	if(root[u] == 0)	return u;
	root[u] = get_root(root[u]);
	return root[u];
}
void join(int u , int v)
{
	u = get_root(u) , v = get_root(v);
	if(u != v)	root[u] = v;
}
void prepare()
{
	foru (i , 1 , n)
	{
		for (pii h : adj[i])	join(i , h.fi);
	}
	foru (i , 1 , n)
	{
		if(get_root(i) == i)
		{
			compid[i] = ++numcomp;
			comps[numcomp].push_back(i);
		}
	}
	foru (i , 1 , n)
	{
		int j = get_root(i);
		if(i != j)	compid[i] = compid[j];
		comps[compid[j]].push_back(i);
	}
}
void dijkstra(int x)
{
	if(visited[x]) 	return;
	visited[x] = 1;
	for (int u : comps[x])
	{
		for (pii h : fromarc[u])	dijkstra(compid[h.fi]);
	}
 	priority_queue<pii> pq;
 	for (int u : comps[x])
 	{
 		if(d[u] < oo)	pq.push({d[u] , u});
 	}
 	while(pq.size())
 	{
 		int u = pq.top().se;
 		ll du = pq.top().fi;
 		pq.pop();
 		if(d[u] != du)	continue;
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
 	for (int u : comps[x])
 	{
 		for (pii h : toarc[u])
 		{
 			int v = h.fi;
 			d[v] = min(d[v] , d[u] + h.se);
 		}
 	}
}
void subfull()
{
	prepare();
	memset(d , 0x3f , sizeof(d));
	d[1] = 0;
	foru (i , 1 , numcomp)	dijkstra(i);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("shortestpath.inp" , "r" , stdin);
    freopen("shortestpath.out" , "w" , stdout);
    cin >> n >> m >> p;
    foru (i , 1 , m)
    {
    	int u , v , c;
    	cin >> u >> v >> c;
    	adj[u].push_back({v , c});
    	adj[v].push_back({u , c});
    }
    foru (i , 1 , p)
    {
    	int u , v , c;
    	cin >> u >> v >> c;
    	toarc[u].push_back({v , c});
    	fromarc[v].push_back({u , c});
    }
    subfull();
    foru (i , 1 , n)
    {
    	if(d[i] > oo) d[i] = -1;
    	cout << d[i] << " ";
    }
    return 0;
}