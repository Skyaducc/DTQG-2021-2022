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
const int MAXN = 2e5 + 1;
int n , numtopo;
int a[MAXN] , color[MAXN] , deg[MAXN] , topo[MAXN] , d[MAXN] , visited[MAXN];
vector<int> adj[MAXN];
void bfs()
{
	queue<int> qu;
	foru (i , 1 , n)
	{
		for (int j : adj[i])
		{
			if(visited[j] || color[i] == color[j])	continue;
			qu.push(j);
			d[j] = 1;
			visited[j] = 1;
		}
	}
	while(qu.size())
	{
		int u = qu.front();
		qu.pop();
		for (int v : adj[u])
		{
			if(!visited[v])
			{
				visited[v] = 1;
				d[v] = min(d[v] , d[u] + 1);
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
    cin >> n;
    foru (i , 1,  n)	cin >> a[i];
    foru (i , 1 , n)	color[i] = (a[i] % 2) ? 1 : 0;
    foru (i , 1 , n)
    {
    	if(i - a[i] >= 1)
    	{
    		adj[i-a[i]].push_back(i);
    	}
    	if(i + a[i] <= n)
    	{
    		adj[i+a[i]].push_back(i);
    	}
    }
    memset(d , 0x3f , sizeof(d));
	bfs();
	foru (i , 1 , n)
	{
		cout << ((d[i] > oo) ? -1 : d[i]) << " ";
	}
    return 0;
}
