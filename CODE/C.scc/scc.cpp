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
const int MAXN = 5001;
int n , m , cnt;
vector<pii> adj[MAXN];
struct Data
{
	int u , v , c;
	bool operator < (const Data &tmp)	const
	{
		return c < tmp.c;
	}
} edge[MAXN];
int low[MAXN] , id[MAXN];
stack<int> st;
bool flag = true;
void tarjan(int u)
{
	low[u] = id[u] = ++cnt;
	st.push(u);
	for (pii h : adj[u])
	{
		int v = h.fi;
		if(id[v])
		{
			low[u] = min(low[u] , id[v]);
		}
		else
		{
			tarjan(v);
			low[u] = min(low[u] , low[v]);
		}
	}
	if (low[u] == id[u])
	{
		int dem = 0;
		while(true)
		{
			int v = st.top();
			st.pop();
			dem++;
			if(dem >= n)	flag = false;
			if (v == u)	break;
		}
	}
}
void Reset()
{
	foru (i , 1 , n)	adj[i].clear();
	reset(low) , reset(id);
	flag = true;
	cnt = 0;
}
bool check(int l , int r)
{	
	Reset();
	int root = 0;
	foru (i , l , r)
	{
		int u = edge[i].u , v = edge[i].v , c = edge[i].c;
		if(!root)	root = u;
		adj[u].push_back({v , c});
	}
	tarjan(root);
	if(!flag)	return true;
	return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("scc.inp" , "r" , stdin);
    freopen("scc.out" , "w" , stdout);
    cin >> n >> m;
   	foru (i , 1 , m)
   	{
   		int u , v , c;
   		cin >> u >> v >> c;
   		edge[i] = {u , v , c};
   	}	
   	sort(edge + 1 , edge + 1 + m);
   	int best = oo;
   	foru (i , 1 , m)
   	{
   		int l = i , r = m , ans = 0 , pos = i;
   		while(l <= r)
   		{
   			int mid = (l + r) / 2; 
   			if(check(pos , mid))
   			{
   				ans = mid;
   				r = mid - 1;
   			}
   			else l = mid + 1;
   		}
   		if(ans)	best = min(best , edge[ans].c - edge[pos].c);
   	} 	
   	if(best == oo)	cout << -1;
   	else	cout << best;
    return 0;
}
