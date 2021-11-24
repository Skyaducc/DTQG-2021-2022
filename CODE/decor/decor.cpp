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
const int MAXN = 5 * 1e5 + 1;
int n , m , k;
int a[MAXN];
vector<int> adj[MAXN] , v;
string s;
set<int> se;
pii far;
bool visited[MAXN];
void dfs(int u)
{
	visited[u] = 1;
	se.insert(u);
	for (int v : adj[u])
	{
		if(!visited[v])	dfs(v);
	}
}
vector<int> ve;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m >> k;
    cin >> s;
	s = " " + s;
	foru (i , 1 , n)
	{
		a[i] = s[i] - '0';
		if(a[i])	v.push_back(i);
	}
    foru (i , 1 , m)
    {
    	int u , v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    for (int x : v)
    {
    	dfs(x);
    	reset(visited);
    }
    for (int x : s)	ve.push_back(x);
    int tmp = 0;
    foru (i , 1 , (int)ve.size() - 1)
	{
		if(ve[i] == ve[i-1] + 1)
		{
			tmp++;
			if(far.fi < tmp) far = {tmp , ve[i]};
		}
		else tmp = 0;
	}
	cout << far.fi << " " << far.se << endl;
    return 0;
}
