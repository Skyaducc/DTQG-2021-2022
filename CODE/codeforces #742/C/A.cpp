#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int , int>
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
int test;
int n;
vector<int> adj[MAXN];
int deg[MAXN];
void solve()
{
	cin >> n;
	foru (i , 1 , n)
	{
		adj[i].clear();
		deg[i] = 0;
	}
	priority_queue<pii , vector<pii> , greater<pii>> pq;
	foru (i , 1 , n)
	{
		int x;
		cin >> x;
		if(x == 0)	pq.push({1 , i});
		foru (j , 1 , x)
		{
			int y;
			cin >> y;
			adj[y].push_back(i);
			deg[i]++;
		}
	}
	int res = -1;
	while(pq.size())
	{
		int day = pq.top().fi;
		int u = pq.top().se;
		pq.pop();
		n--;
		if(day > res || res == -1) res = day;
		for (int v : adj[u])
		{
			if(--deg[v] == 0)
			{
				if(v > u)	pq.push({day , v});
				else pq.push({day + 1 , v});
			}
		}
	}
	if(n)	res = -1;
	cout << res << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> test;
    while(test--)
    {
    	solve();
    }
    return 0;
}