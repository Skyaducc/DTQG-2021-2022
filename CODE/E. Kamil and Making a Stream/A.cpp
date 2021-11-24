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
const int MAXN = 3e5 + 1;
int q , n;
pii a[MAXN];
int f[MAXN][4];
void solve()
{
	cin >> n;
	foru (i , 1 , n)
	{
		cin >> a[i].fi >> a[i].se;
	}
	foru (i , 1 , n)
	{
		f[i][0] = f[i][1] = f[i][2] = oo;
		foru (j , 0 , 2)
		{
			foru (k , 0 , 2)
			{
				if(a[i-1].fi + j != a[i].fi + k)
				{
					f[i][k] = min(f[i][k] , f[i-1][j] + k * a[i].se);
				}
			}
		}
	}
	cout << min({f[n][0] , f[n][1] , f[n][2]}) << endl;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> q;
    while(q--)
    {
    	solve();
    }
    return 0;
}
