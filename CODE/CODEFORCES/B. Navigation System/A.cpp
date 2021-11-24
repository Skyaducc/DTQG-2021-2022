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
const int MAXN = 2 * 1e5 + 1;
int n , m , k;
vector<pii> adj[MAXN] , adj1[MAXN];
int a[MAXN] , d[MAXN] , trace[MAXN];
void dijkstra(int s , int t)
{
	foru (i , 1 , n)	d[i] = oo;
	priority_queue<pii , vector<pii> , greater<pii> > pq;
	d[s] = 0;
	pq.push({0 , s});
	while(pq.size())
	{
		int u = pq.top().se;
		int du = pq.top().fi;
		pq.pop();
		if(d[u] != du)	continue;
		for (pii h : adj1[u])
		{
			int v = h.fi , uv = h.se;
			if(d[v] > du + uv)
			{
				d[v] = du + uv;
				pq.push({d[v] , v});
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
    cin >> n >> m;
    foru(i , 1 , m)
    {
    	int u , v;
    	cin >> u >> v;
    	adj[u].push_back({v , 1});
    	adj1[v].push_back({u , 1});
    }
    cin >> k;
    foru(i , 1 , k)
    {
    	cin >> a[i];
    }
    dijkstra(a[k] , a[k]);
    int ans1 = 0 , ans2 = 0;
    // foru(i , 1 , k)	cout << d[a[i]] << " " ;
    // cout << endl;
    foru(i , 1 , k)
    {
    	if(d[a[i+1]] > d[a[i]] - 1 && i != k)	ans1++;
    	else
    	{
    		for (pii h : adj[a[i]])
	    	{
	    		int v = h.fi;
	    		if(v == a[i+1])	continue;
	    		if(d[a[i]] == d[v] + 1)	
	    		{
	    			ans2++;
	    			break;
	    		}
	    	}
    	}
    }
    cout << ans1 << " " << ans2 + ans1;
    return 0;
}
