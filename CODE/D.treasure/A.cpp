#include <iostream>
#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
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
const int oo = 1e9;
const int MAXN = 2e5 + 11;
int n , m , k , q;
pii a[MAXN];
int col[MAXN] , prefixsum[MAXN];
int Left[MAXN] , Right[MAXN]; // left(i) : cột nhỏ nhất tại hàng i , right(i) : cột lớn nhất
int dp[MAXN][2]; // 0 : left , 1 : right
void input()
{
	cin >> n >> m >> k >> q;
	foru (i , 1 , n)	Left[i] = oo , Right[i] = -oo; 
    foru (i , 1 , k)
    {
    	cin >> a[i].fi >> a[i].se;
    	Left[a[i].fi] = min(Left[a[i].fi] , a[i].se);
    	Right[a[i].fi] = max(Right[a[i].fi] , a[i].se);
    }
    Left[1] = min(Left[1] , 1LL);
    Right[1] = max(Right[1] , 1LL);
    foru (i , 1 , q)	cin >> col[i];
    sort(col + 1 , col + 1 + q);
}
int Calc(int j , int u , int i , int v)
{
	int ret = oo;
	int x = (u == 0) ? Left[j] : Right[j];
	int y = (v == 0) ? Left[i] : Right[i];
	int x1 = (u == 0) ? Right[j] : Left[j];
	int y1 = (v == 0) ? Right[i] : Left[i];
	int p = lower_bound(col + 1 , col + q + 1 , x) - col;
	if (p <= q)	ret = abs(x - col[p]) + abs(y1 - col[p]) + abs(y - y1);
	p = upper_bound(col + 1 , col + q + 1 , x) - col - 1;
	if(p) ret = min(ret , abs(x - col[p]) + abs(y1 - col[p]) + abs(y - y1));
	return ret;
}
void solve()
{
    memset(dp , 0x3f , sizeof(dp));
    dp[1][0] = Right[1] - Left[1] + Right[1] - 1;
    dp[1][1] = Right[1] - Left[1];
    int prev_i = 1;
    foru (i , 2 , n)
    {	
    	if(Left[i] == oo)	continue;
    	foru (j , 0 , 1) // trạng thái hàng tiếp theo
    	{
    		foru (k , 0 , 1) // trạng thái hàng hiện tại
    		{
    			dp[i][j] = min(dp[i][j] , dp[prev_i][k] + Calc(prev_i , k , i , j) + i - prev_i);
    		}
    	}
    	prev_i = i;
    }
    cout << min(dp[prev_i][0] , dp[prev_i][1]);
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    input();
    solve();
    return 0;
}