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
const int MAXN = 1e5 + 11;
int a[MAXN];
int n , m;
vector<pii> adj[MAXN];
int cake[MAXN];
struct Data
{
	int u;
	long long dist , numcake;
	bool operator > (const Data &tmp)	const
	{
		if(dist == tmp.dist)	return numcake < tmp.numcake;
		else	return dist > tmp.dist;
	}
};
long long d[MAXN];
void dijkstra()
{
	foru (i , 1 , n)	d[i] = oo;
	priority_queue<Data , vector<Data> , greater<Data> > pq;
	d[1] = 0;
	pq.push({1 , 0 , a[1]});
	while(pq.size())
	{
		int u = pq.top().u;
		long long du = pq.top().dist;
		long long numcake = pq.top().numcake;
		pq.pop();
		if(d[u] != du)	continue;
		for (pii h : adj[u])
		{
			int v = h.fi;
			int uv = h.se;
			if(d[v] == d[u] + uv)
			{
				if(cake[v] < numcake + a[v])
				{
					cake[v] = numcake + a[v];
					pq.push({v , d[v] , cake[v]});
				}
			}
			if(d[v] > d[u] + uv)
			{
				d[v] = d[u] + uv;
				cake[v] = numcake + a[v];
				pq.push({v , d[v] , numcake + a[v]});
			}
		}
	}
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("quanho.inp" , "r" , stdin);
    freopen("quanho.out" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)	cin >> a[i];
    cin >> m;
    foru (i , 1 , m)
    {
    	int u , v , c;
    	cin >> u >> v >> c;
    	adj[u].push_back({v , c});
    	adj[v].push_back({u , c});
    }
    dijkstra();
    if(d[n] == oo)
    {
    	cout << "impossible";
    	return 0;
    }
    cout << d[n] << " " << cake[n];
    return 0;
}
