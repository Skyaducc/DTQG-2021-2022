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
int n , m;
int a[MAXN];
map<int , int> mp;
vector<int> res;
long long ans = 0;
void bfs()
{
	queue<pii> qu;
	foru (i , 1 , n)	qu.push({a[i] , a[i]}) , mp[a[i]] = 1;
	while((int)res.size() != m)
	{
		int u = qu.front().fi;
		int v = qu.front().se;
		qu.pop();
		if(mp[u] == 0)
		{
			res.push_back(u);
			ans += abs(u - v);
			mp[u] = 1;
		}
		if(mp[u+1] == 0)
		{
			qu.push({u + 1 , v});
		}
		if(mp[u-1] == 0)
		{
			qu.push({u - 1 , v});
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
    foru (i , 1 , n)	cin >> a[i];
    bfs();
    cout << ans << endl;
    for (int x : res)	cout << x << " ";
    return 0;
}
