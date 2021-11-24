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
const int oo = 1e9;
const int MAXN = 2e5 + 1;
int n , m , k;
int a[MAXN];
int dp[MAXN][201];
int MAX[MAXN][18][2]; 
void sub2()
{
	foru (x , 1 , k)
	{
		foru (i , 1 , n)
		{
			int ma = 0;
			ford (j , i - 1 , max(1LL , i - m))
			{
				ma = max(ma , dp[j][x-1]);
			}
			dp[i][x] += ma + a[i] * x;
		}
	}
	int ans = 0;
	foru (i , 1 , n)	ans = max(ans , dp[i][k]);
	cout << ans;
}
int get_max(int l , int r , int x)
{
	int k = log2(r - l + 1);
	return max(MAX[l][k][x] , MAX[r - (1 << k) + 1][k][x]);
}
void subfull()
{
	foru (x , 1 , k)
	{
		bool cur = x & 1;
		bool pre = !cur;
		foru (i , 1 , n)
		{
			int ma = get_max(max(1LL , i - m) , i - 1 , pre);
			dp[i][x] += ma + a[i] * x;
			MAX[i][0][cur] = dp[i][x];
		}
		foru (j , 1 , 18)
		{
			foru (i , 1 , n - (1 << j))
			{
				MAX[i][j][cur] = max(MAX[i][j-1][cur] , MAX[i + (1 << (j - 1))][j-1][cur]);
			}
		}
	}
	int ans = 0;
	foru (i , 1 , n)	ans = max(ans , dp[i][k]);
	cout << ans;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.ANS" , "w" , stdout);
    cin >> n >> m >> k;
    foru (i , 1 , n)	cin >> a[i];
    if(n <= 2000)	sub2();
    // else subfull();
    // subfull();
    return 0;
}
