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
int n , m;
int dp[MAXN];
vector<int> adj[MAXN];
int deg[MAXN];
void bfs()
{
	queue<int> qu;
	foru (i , 1 , n)	if(deg[i] == 0)	qu.push(i);
	while(qu.size())
	{
		int u = qu.front();
		qu.pop();
		for (int v : adj[u])
		{
			dp[v] = max(dp[v] , dp[u] + 1);
			if(--deg[v] == 0)
			{
				qu.push(v);
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
    foru (i , 1 , m)
    {
    	int u , v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	deg[v]++;
    }
    bfs();
    int ans = 0;
    foru (i , 1 , n)	ans = max(ans , dp[i]);	
    cout << ans;
    return 0;
}