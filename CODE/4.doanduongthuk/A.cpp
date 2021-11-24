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
const long long oo = 1e18;
const int MAXN = 2e5 + 11;
int n , m , k;
vector<pii> adj[MAXN];
struct Data
{
	int u , v , w;
	bool operator < (const Data &tmp)	const 
	{
		return w < tmp.w;
	}
};
vector<Data> List;
long long dist[MAXN];
vector<long long> ve;
void dijkstra(int x)
{
	foru (i , 1 , n)	dist[i] = oo;
	dist[x] = 0;
	priority_queue<pair<long long , int> , vector<pair<long long , int>> , greater<pair<long long , int>> > pq;
	pq.push({0 , x});
	while(pq.size())
	{
		int u = pq.top().se;
		long long du = pq.top().fi;
		pq.pop();
		if(du != dist[u])	continue;
		for (pii h : adj[u])
		{
			int v = h.fi;
			long long uv = h.se;
			if(dist[v] > dist[u] + uv)
			{
				dist[v] = dist[u] + uv;
				pq.push({dist[v] , v});
			}
		}
	}
	foru (i , x + 1 , n) ve.push_back(dist[i]);
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
    	int u , v , w;
    	cin >> u >> v >> w;
    	List.push_back({u , v , w});
    }
    sort(List.begin() , List.end());
	vector <int> arr;
	foru(i , 0 , min(m , k)) 
	{
		arr.push_back(List[i].u);
		arr.push_back(List[i].v);
	}
	sort(arr.begin() , arr.end());
	arr.resize(unique(arr.begin() , arr.end()) - arr.begin());
	foru (i , 0 , min(k , m)) 
	{
		int u = lower_bound(arr.begin() , arr.end() , List[i].u) - arr.begin() + 1;
		int v = lower_bound(arr.begin() , arr.end() , List[i].v) - arr.begin() + 1;
		adj[u].push_back({v , List[i].w});
		adj[v].push_back({u , List[i].w});
	}
	n = (int)arr.size();
	foru (i , 1 , (int)arr.size() - 1) dijkstra(i);
	sort(ve.begin() , ve.end());
	cout << ve[k-1];
    return 0;
}