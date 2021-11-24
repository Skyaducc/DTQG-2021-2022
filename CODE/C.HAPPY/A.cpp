// 1 1
// 0 2
// 1 0 
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
const int MOD = 1e9 + 7;
const int MAXN = 351;
int n;
int f[MAXN][MAXN] , g[MAXN][MAXN];
int fact[MAXN] , finv[MAXN];
int pw(int a,int b)
{
    if (b == 0)	return 1;
    if (b == 1)	return a;
    int tmp = pw(a , b / 2);
    if (b % 2 == 0)	return tmp * tmp % MOD;
    else	return ((a * tmp) % MOD * tmp) % MOD;
}
void ckn()
{
    fact[0] = finv[0] = 1;
    foru (i , 1 , MAXN - 1)
    {
        fact[i] = fact[i-1] * i % MOD;
        finv[i] = pw(fact[i] , MOD - 2);
    }
}
void add(int &x , int y)
{
	x += y;
	if(x >= MOD)	x -= MOD;
}
int ckn (int k , int n)
{
    if (k > n)
    {
        return 0;
    }
    return 1ll * fact[n] * finv[k] % MOD * finv[n-k] % MOD;
}
int c[MAXN][MAXN];

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> n;
    f[0][0] = g[0][0] = 1;
    c[0][0] = 1;
    foru (i , 0 , n)
    {
    	c[i][0] = c[i][i] = 1;
    	foru (j , 1 , i)
    	{
    		c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
    	}
    }
    foru (i , 1 , n)
    {
    	foru (j , 0 , n)
    	{
    		foru (z , 0 , j)
    		{
    			f[i][j] = (f[i][j] + f[i-1][j-z] * c[j][z] % MOD) % MOD;
    			if(z != i)	
    			{
    				g[i][j] = (g[i][j] + g[i-1][j-z] * c[j][z] % MOD) % MOD;
    			}
    		}
    	}
    }
    // cout << f[n][n] << " " << g[n][n] << endl;
    int res = f[n][n] - g[n][n];
    if(res < 0)	res += MOD;
   	cout << res;
    return 0;
}