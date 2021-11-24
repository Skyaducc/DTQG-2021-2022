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
const int LOGN = 20;
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
Data b[MAXN];
int Get_root(int u)
{
    return (root[u]) ? root[u] = Get_root(root[u]) : u;
}
int res[MAXN];
int par[MAXN][LOGN + 1] , h[MAXN];
int dist[MAXN][LOGN + 1];
map<int , int> mp;
vector<int> f[MAXN];
int visited[MAXN];
void dfs(int u)
{
    for (pii x : adj[u])
    {
    	int v = x.fi;
        if (v == par[u][0]) continue;
        par[v][0] = u;
        dist[v][0] = x.se;
        foru (j , 1 , 18)   par[v][j] = par[par[v][j-1]][j-1];
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
bool check(int u , int v , int w)
{
	int c = get(u , v);
	if(c >= w)	return true;
	return false;
}
void init()
{
	h[1] = 1;
	dfs(1);
	foru (j , 1 , 18)
	{
		foru (i , 1 , n)
		{
			dist[i][j] = max(dist[i][j-1] , dist[par[i][j-1]][j-1]);
		}
	}
}
int id[MAXN] , low[MAXN] , cha[MAXN] , cnt = 0;
map<int , int> mark[MAXN];
void DFS(int u)
{
    low[u] = id[u] = ++ cnt;
    for (int v : f[u])
    {
        if (v != cha[u])
        {
            if (id[v] != 0) low[u] = min(low[u], id[v]);
            else
            {
                cha[v] = u;
                DFS(v);
                low[u] = min(low[u], low[v]);
                if (low[v] == id[v])
                {
                	// cout << u << " " << v << endl;
                    mark[u][v] = mark[v][u] = 1;
                }
            }
        }
    }
}
map<int , int> ve;
void Kruskal()
{
    sort(a + 1 , a + m + 1);
    vector<int> v;
    foru (i , 1 , m)
    {
        int p = Get_root(a[i].u);
        int q = Get_root(a[i].v);
        if (p != q)
        {
            root[p] = q;
            res[a[i].id] = 1;
            // cout << a[i].u << " " << a[i].v << " " << a[i].w << endl;
            adj[a[i].u].push_back({a[i].v , a[i].w});
            adj[a[i].v].push_back({a[i].u , a[i].w});
        }
    }
    init();
    foru (i , 1 , m)
    {
    	if(!res[a[i].id])
    	{
    		if(check(a[i].u , a[i].v , a[i].w))
    		{
    			ve[a[i].w] = 1;
    		}
    	}
    }
    DFS(1);
    foru (i , 1 , m)
    {	
    	if((res[i] && !ve[b[i].w]) || (res[i] && mark[a[i].u][a[i].v]))	cout << "Yes" << " ";
    	else	cout << "No" << " ";
    }
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
    	f[u].push_back(v);
    	f[v].push_back(u);
    	b[i] = a[i];
    }
    Kruskal();
    return 0;
}
