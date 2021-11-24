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
const int MAXN = 2e5 + 11;
int n , m;
struct Data
{
	int x , c , w;
	bool operator < (const Data &tmp)	const
	{
		return x < tmp.x;
	}
} a[2 * MAXN];
int cp_r , cp_g , res = oo , sum_gw , sum_rw;
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
    	int p , w , d;
    	cin >> p >> w >> d;
    	a[++m] = {p - d , 0 , w}; // do
    	a[++m] = {p + d , 1 , w}; // xanh
    }
    sort(a + 1 , a + 1 + m);
    foru (i , 2 , m)
    {
    	if(a[i].c == 0) 
    	{
    		cp_r += (a[i].x - a[1].x) * a[i].w;
    		sum_rw += a[i].w;
    	}
    }
    res = min(res , cp_g + cp_r);
    foru (i , 2 , m)
    {	
    	cp_r -= (a[i].x - a[i-1].x) * sum_rw;
    	if(a[i].c == 0)	sum_rw -= a[i].w;
    	cp_g += (a[i].x - a[i-1].x) * sum_gw;
    	if(a[i].c == 1)	sum_gw += a[i].w;
    	res = min(res , cp_g + cp_r);
    	// cout << a[i].x << " " << a[i].c << " " << a[i].w << " " << cp_r << " " << cp_g << " " << sum_rw << " " << sum_gw << endl;
    }	
    cout << res;
    return 0;
}