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
const int MAXN = 2217;
const int MOD = 998244353;
int c[MAXN] , a[MAXN] , n , d , res;
void backtrack(int i)
{
	foru (j , 0 , 2)
	{
		a[i] = j;
		if(i == n)
		{
			int A = 0 , b = 0;
	        foru (i , 1 , n)
	        {
	            if (a[i] > 0LL) b += c[i];
	            if (a[i] > 1LL) A += c[i];
	        }
	        res += (b - A <= d && b > 0 && A > 0);
		}
		else backtrack (i + 1);
	}
}
void sub1()
{
    backtrack(1);
    cout << res;
}
void sub2()
{
	res = 1;
	foru (i , 1 , n)	res = (res * 2LL) % MOD;
    cout << res - 1;
}
long long f[MAXN][5700] , g[MAXN][5700];
void subfull()
{
	f[0][0] = 1;
    g[0][0] = 1;
    foru (i , 1 , n)
    {
        foru (j , 0 , d)
        {
            if (c[i] <= j) f[i][j] = (f[i - 1][j] * 2 + f[i - 1][j - c[i]]) % MOD;
            else f[i][j] = (f[i - 1][j] * 2) % MOD;
            if (c[i] <= j) g[i][j] = (g[i - 1][j] + g[i - 1][j - c[i]]) % MOD;
            else g[i][j] = g[i - 1][j];
        }
    }
    long long res = 0;
    foru (i , 0 , d)
    {
        res = (res + f[n][i] - g[n][i]) % MOD;
    }
    if (res < 0) res += MOD;
    cout << res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("subsubset.inp" , "r" , stdin);
    freopen("subsubset.out" , "w" , stdout);
    cin >> n >> d;
    foru (i , 1 , n)	cin >> c[i];
    // if (d == 0) sub2();
    // else subfull();
    subfull();
    return 0;
}