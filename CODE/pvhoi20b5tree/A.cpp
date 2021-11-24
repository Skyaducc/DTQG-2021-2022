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
const int MAXN = 1e5 + 1;
int n , k , p;
int deg[MAXN];
vector<int> adj[MAXN];
void sub3()
{
	cout << 1LL * n * (n - 1) % p;
}
int res = 0 , cnt;
int x[21] , num[MAXN];
void dfs(int u , int par)
{
    bool check = (x[u] != 1);
    for (int v : adj[u])
    {
        if(v == par) continue;
        dfs(v , u);
        num[u] += num[v];
        if(num[v] == k) check = false;
    }
    if(num[u] == 0) check = false;
    if(check) ++res;
}
void check()
{
	int dem = 0;
	foru (i , 1 , n)	
	{
		num[i] = x[i];
		dem += (x[i] == 1);
	}
	if(dem != k)	return;
    dfs(1 , -1);
}
void backtrack(int i)
{
	foru (j , 0 , 1)
	{
		x[i] = j;
		if(i == n)	check();
		else backtrack(i + 1);
	}
}
void sub1()
{
	backtrack(1);
	cout << res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> k >> p;
    foru (i , 1 , n - 1)
    {
    	int u , v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    if(k == 1)
    {
    	sub3();
    	return 0;
    }
    if(n <= 20)
    {
    	sub1();
    	return 0;
    }
    return 0;
}