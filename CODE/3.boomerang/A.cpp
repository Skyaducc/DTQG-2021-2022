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
const int MAXN = 2e5 + 11;
int q , n = 1;
vector<pii> adj[MAXN];
int d[MAXN] , TimeIn[MAXN] , TimeOut[MAXN] , cnt;
struct query
{
	int type , a , b;
};
vector<query> v;
vector<int> res;
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
set<int> s[MAXN * 30];
int Count;
int Child[MAXN * 30][2];
void add(int u , int val)
{
	int node = 0;
	ford(i , 30 , 0)
	{
		int x = BIT(d[u] , i);
		if(Child[node][x] == 0)
		{
			Child[node][x] = ++Count;
		}
		node = Child[node][x];
		s[node].insert(TimeIn[u]);
	}
}
void DFS(int node , int Bit , int val , int b , int ans)
{
    if(Bit < 0) return;
	int x = BIT(val , Bit);
	int x1 = !x;
	bool ok = true;
	if(Child[node][x1])
	{
		int v = Child[node][x1];
		auto tmp = s[v].lower_bound(TimeIn[b]);
		if(tmp == s[v].end() || *tmp > TimeOut[b])
        {
            ok = false;
        }
		if(ok)
        {
            ans += (x1 == 1) ? (1 << Bit) : 0;
            res.push_back(x1);
            DFS(v , Bit - 1 , val , b , ans);
        }
	}
	if(!Child[node][x1] || !ok)
	{
		int v = Child[node][x];
		if(v != 0)
		{
		    res.push_back(x);
			int tmp = *s[v].lower_bound(TimeIn[b]);
			ans += (x == 1) ? (1 << Bit) : 0;
			if(tmp <= TimeOut[b])
			{
				DFS(v , Bit - 1 , val , b , ans);
			}
		}
	}
}
int get(int val , int b)
{
	res.clear();
	DFS(0 , 30 , val , b , 0);
    reverse(res.begin() , res.end());
    int ans = 0;
    if(res.size() == 0) return  val;
    foru (i , 0 , res.size() - 1)
    {
        ans += (res[i] == 1) ? (1 << i) : 0;
    }
    return ans ^ val;
}
main()
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
    add(1 , 0);
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
    set<int> se;
    return 0;
}
