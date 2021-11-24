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
const int MAXN = 2e5 + 11;
int q , n = 1;
vector<pii> adj[MAXN];
int d[MAXN] , TimeIn[MAXN] , TimeOut[MAXN] , cnt;
struct query
{
	int type , a , b;
};
vector<query> v;
void dfs(int u , int par , int val)
{
	TimeIn[u] = ++cnt;
	d[u] = d[par] ^ val;
	for (pii h : adj[u])
	{
		int v = h.fi;
		int uv = h.se;
		if(v == par)	continue;
		dfs(v , u , uv);
	}
	TimeOut[u] = cnt;
}
set<int> s[MAXN];
int Count;
int Child[MAXN][2];
void add(int u , int val)
{
	int node = 0;
	foru (i , 0 , log2(val))
	{
		int x = BIT(d[u] , i);
		if(Child[node][x] == 0)
		{
			Child[node][x] = ++Count;
			s[Count].insert(TimeIn[u]);
		}
		node = Child[node][x];
	}
}
int res;
void DFS(int node , int Bit , int val , int b , int ans)
{
	int x = BIT(val , Bit);
	int x1 = !x;
	res = max(res , ans);
	if(Child[node][x1])
	{
		int v = Child[node][x1];
		int tmp = *s[v].lower_bound(TimeIn[b]);
		ans += (x1 == 1) ? (1 << Bit) : 0;
		if(tmp <= TimeOut[b])
		{
			DFS(v , Bit + 1 , val , b , ans);
		}
	}
	else
	{
		int v = Child[node][x];
		if(v != 0)
		{
			int tmp = *s[v].lower_bound(TimeIn[b]);
			ans += (x == 1) ? (1 << Bit) : 0;
			if(tmp <= TimeOut[b])
			{
				DFS(v , Bit + 1 , val , b , ans);
			}
		}
	}
}
int get(int val , int b)
{
	res = 0;
	DFS(0 , 0 , val , b , 0);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> q;
    foru (i , 1 , q)
    {
    	string s;
    	int u , w;
    	cin >> s >> u >> w;
    	if(s == "Add")
    	{
    		++n;
    		adj[u].push_back({n , w});
    		adj[n].push_back({u , w});
    		v.push_back({0 , n , 1});
    	}
    	else
    	{
    		v.push_back({1 , u , w});
    	}
    }
    dfs(1 , 0 , 0);
    for (query x : v)
    {
    	if(x.type == 0)
    	{
    		add(x.a , d[x.a]);
    	}
    	else
    	{
    		cout << get(d[x.a] , x.b) << endl;
    	}
    }
    return 0;
}
