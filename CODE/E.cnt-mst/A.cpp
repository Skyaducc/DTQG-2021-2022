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
const int MOD = 998244353;
int subtask , n , m;
vector<pii> adj[MAXN];
bool flag[MAXN];
struct data
{
	int u , v , c;
	data(int _u = 0 , int _v = 0 , int _c = 0)
	{
		u = _u , v = _v , c = _c;
	}
	bool operator < (const data &tmp)	const
	{
		return c < tmp.c;
	}
} edge[MAXN];
struct disjoinset
{
	vector<int> root;
	int n;
	disjoinset (int _n = 0)
	{
		n = _n;
		root.assign(n + 1 , 0);
	}
	int get_root(int u)
	{
		return (root[u] == 0) ? u : root[u] = get_root(root[u]);
	}
	bool join(int u , int v)
	{
		u = get_root(u) , v = get_root(v);
		if(u == v)	return false;
		root[v] = u;
		return true;
	}
};
int a[MAXN];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("cnt-mst.inp" , "r" , stdin);
    freopen("cnt-mst.out" , "w" , stdout);
    cin >> subtask >> n >> m;
    foru (i , 1 , m)
    {
    	int u , v , c;
    	cin >> u >> v >> c;
    	edge[i] = {u , v , c};
    }
    sort(edge + 1 , edge + 1 + m);
    disjoinset dsu(n);
    int ans = 1;
    foru (i , 1 , m)
    {
    	int j = i , cnt = 0 , num = 0 , res = 0;
    	vector<data> ve;
    	while(j <= m && edge[j].c == edge[i].c)	
    	{
    		ve.push_back(edge[j]);
    		j++;
    	}
    	// cout << i << " " << j << " " << edge[i].c << " " << edge[j].c << endl;
    	i = j - 1;	
    	foru (j , 0 , (int)ve.size() - 1)
    	{
    		int u = ve[j].u , v = ve[j].v;
    		u = dsu.get_root(u) , v = dsu.get_root(v);
    		ve[j].u = u , ve[j].v = v;
    		// if(!a[u])	a[u] = ++num;
    		// if(!a[v])	a[v] = ++num;
    	}
    	int last = (1 << (int)(ve.size())) - 1;
    	for(data x : ve)
    	{
    		int u = x.u , v = x.v;
    		if(dsu.join(u , v))	cnt++;
    	}
    	// cout << ve.size() << endl;
    	// cout << cnt << " " << last << endl;
    	foru (mask , 0 , last)
    	{
    		int k = __builtin_popcount(mask);
    		if(k != cnt)	continue;
    		// cout << mask << endl;
    		disjoinset d(num+1);
    		bool ok = true;
    		foru (j , 0 , (int)ve.size() - 1)
    		{
    			if(BIT(mask , j))
    			{
    				if(!d.join(a[ve[j].u] , a[ve[j].v]))
    				{
    					ok = false;
    					break;
    				}
    			}
    		}	
    		// if(ok)	cout << mask << " ";
    		res += ok;
    	}
    	// cout << endl;
    	ans = (ans * res) % MOD;
    	for (auto x : ve)	a[x.u] = a[x.v] = 0;
    }
    cout << ans;
    return 0;
}
