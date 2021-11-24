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
const int MAXN = 3e5 + 1;
const int MOD = 998244353;
int subtask , n , m , cnt;
vector<pii> adj[MAXN];
int visited[MAXN] , low[MAXN] , id[MAXN];
vector<pii> ve;
long long res1[MAXN] , res2[MAXN] , temp[MAXN] , Count[MAXN];
void tarjan(int u , int par = -1)
{
    visited[u] = true;
    Count[u] = 1;
    low[u] = id[u] = ++cnt;
    long long sum = 0;
    for (pii h : adj[u]) 
    {
    	int v = h.fi;
    	int idx = h.se;
    	if (v != par)
    	{
	        if (visited[v])
	        {
	            low[u] = min(low[u] , id[v]);
	        }
	        else 
	        {
	            tarjan(v , u);
	            Count[u] += Count[v];
	            low[u] = min(low[u] , low[v]);
	            if (low[v] >= id[v])
	            {
	            	res2[idx] = 1LL * Count[v] * (n - Count[v]) % MOD;
	            }
	            if(low[v] >= id[u])
	            {
	            	res1[u] += 1LL * sum * Count[v] % MOD;
	            	sum += Count[v];
	            }
	        }
    	}
    }
    res1[u] += 1LL * (n - sum - 1) * sum % MOD;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> subtask >> n >> m;
    foru (i , 1 , m)
    {
    	int u , v;
    	cin >> u >> v;
    	adj[u].push_back({v , i});
    	adj[v].push_back({u , i});
    }
    foru (i , 1 , n)
    {
    	visited[i] = false;
    	temp[i] = 1;
    }
    foru (i , 1 , n)	
    {
        if (!visited[i])
        {
            tarjan(i);
        }
    }
    foru (i , 1 , n)
    {	
    	cout << res1[i] << " ";
    }
    cout << endl;
    foru (i , 1 , m)
    {
    	cout << res2[i] << " ";
    }
    return 0;
}