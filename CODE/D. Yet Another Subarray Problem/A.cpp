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
#define int long long
using namespace std;
const int oo = 1e9;
const int MAXN = 3e5 + 1;
int n , m , k;
int a[MAXN];
int sum[MAXN];
int Minsum[MAXN][11];
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n >> m >> k;
    foru (i , 1 , n)
    {
    	cin >> a[i];
    	sum[i] = sum[i-1] + a[i];
    }
    memset(Minsum , 0x3f , sizeof(Minsum));
    Minsum[0][0] = 0;
    int res = -oo;
    foru (i , 1 , n)
    {
    	sum[i] -= ceil(i / m) * k;
    	foru (r , 0 , m - 1)
    	{
    		int cost = (i % m <= r) ? 0 : k;
    		res = max(res , sum[i] - Minsum[i-1][r] - cost);
    		Minsum[i][r] = Minsum[i-1][r];
    		if(r == i % m)	Minsum[i][r] = min(Minsum[i][r] , sum[i]);
    	}
    }
    cout << max(res , 0LL);
    return 0;
}