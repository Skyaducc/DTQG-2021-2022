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
const int MAXN = 500001;
const int LOGN = 17;
int subtask , n , m;
int root[MAXN];
vector<pii> adj[MAXN];
struct Data
{
    int u , v , w , id;
    bool operator < (const Data &tmp)   const
    {
        return w < tmp.w;
    }
} a[MAXN];
int Get_root(int u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}
int res[MAXN];
int par[MAXN][LOGN + 1] , h[MAXN];
int dist[MAXN][LOGN + 1];
void dfs(int u)
{
    for (pii x : adj[u])
    {
    	int v = x.fi;
        if (v == par[u][0]) continue;
        par[v][0] = u;
        dist[v][0] = x.se;
        foru (j , 1 , 17)
        {
        	par[v][j] = par[par[v][j-1]][j-1];
			dist[v][j] = max(dist[v][j-1] , dist[par[v][j-1]][j-1]);
		}
        h[v] = h[u] + 1;
        dfs(v);
    }
}
int get(int u , int v)
{
    int ans = 0;
    if(u == v) return 0;
    if(h[u] < h[v]) swap(u , v);
    ford (j , LOGN , 0)
    {
        if(h[par[u][j]] >= h[v])
        {
            ans = max(ans , dist[u][j]);
            u = par[u][j];
        }
    }
    if(u == v) return ans;
    ford (j , LOGN , 0)
    {
        while(par[u][j] != par[v][j])
        {
            ans = max(ans , max(dist[u][j] , dist[v][j]));
            u = par[u][j];
            v = par[v][j];
        }
    }
    ans = max(ans , max(dist[u][0] , dist[v][0]));
    return ans;
}
void Kruskal()
{
    sort(a + 1 , a + m + 1);
    foru (i , 1 , m)
    {
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p != q)
        {
            root[p] = q;
            res[a[i].id] = 1;
            adj[a[i].u].push_back({a[i].v , a[i].w});
            adj[a[i].v].push_back({a[i].u , a[i].w});
        }
    }
    h[1] = 1;
    dfs(1);
    foru (i , 1 , m)
    {
    	if(!res[a[i].id])
    	{
    		int temp = get(a[i].u , a[i].v);
    		if(temp >= a[i].w)	res[a[i].id] = 1;
    	}
    }
    foru (i , 1 , m)	cout << ((res[i]) ? "Yes" : "No") << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("mst.inp" , "r" , stdin);
    freopen("mst.out" , "w" , stdout);
    cin >> subtask >> n >> m;
    foru (i , 1 , m)
    {
    	int u , v , c;
    	cin >> u >> v >> c;
    	a[i] = {u , v , c , i};
    }
    Kruskal();
    return 0;
}
