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
const int MAXN = 100001;
int n , m , k;
int color[MAXN];
pii edge[MAXN];
int get_root(int u)
{
	if(root[u] == 0)	return u;
	root[u] = get_root(root[u]);
	return root[u];
}
bool join(int u , int v)
{
	u = get_root(u) , v = get_root(v);
	if(u == v)	return true;
	return false;
}
int solve(int mask)
{
	reset(root);
	int x = 0;
	foru (i , 1 , m)
	{
		int u = edge[i].fi , v = edge[i].se;
		if(u > v)	swap(u , v);
		if(BIT(mask , color[u] - 1) && BIT(mask , color[v] - 1))
		{
			if(!join(u , v))
			{
				root[u] = v;
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
    cin >> n >> m >> k;
    foru (i , 1 , n)	cin >> color[i];
    foru (i , 1 , m)
    {
    	int u , v;
    	cin >> u >> v;
    	edge[i] = {u , v};
    }
    int last = (1 << k);
    int res = 0;
    foru (mask , 2 , last)
    {
    	res += solve(mask);
    }
    cout << res;
    return 0;
}
