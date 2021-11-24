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
#define int long long
using namespace std;
const int oo = 1e18;
const int MAXN = 1e5 + 1;
int n , m;
int a[MAXN] , b[MAXN] , par[MAXN] , d[MAXN];
int solve(int x)
{
	int res = oo;
	queue<int> qu;
	memset(par , 0 , sizeof(par));
	memset(d , 0 , sizeof(d));
	qu.push(x);
	par[x] = -1;
	while(qu.size())
	{
		int u = qu.front();
		qu.pop();
		foru (v , 1 , m)
		{
			if(u != v && (b[u] & b[v]) != 0 && v != par[u])
			{
				if(par[v] == 0)
				{
					par[v] = u;
					d[v] = d[u] + 1;
					qu.push(v);
				}
				else
				{
					res = min(res , d[v] + d[u] + 1);
				}
			}
		}
	}
	return res;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
    	cin >> a[i];
    	if(a[i])	b[++m] = a[i];
    }
    int res = oo;
    if(m > 200)
    {
    	cout << 3;
    }
    else
    {
    	foru (i , 1 , m)	res = min(res , solve(i));
    	cout << ((res == oo) ? -1 : res);
    }
    return 0;
}
