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
const int MAXN = 3e5 + 1;
const int MOD = 998244353;
int n;
pii a[MAXN];
int fact[MAXN];
int cnt[2][MAXN];
void add(int &x , int y)
{
	x += y;
	if(x >= MOD)	x -= MOD;
}
void sub(int &x , int y)
{
	x -= y;
	if(x < 0)	x += MOD;
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
    	cin >> a[i].fi >> a[i].se;
    	cnt[0][a[i].fi]++;
    	cnt[1][a[i].se]++;
    }
    fact[0] = fact[1] = 1;
    foru (i , 2 , MAXN - 1)		fact[i] = (fact[i-1] * i) % MOD;
    int res = fact[n];
    int tmp1 = 1 , tmp2 = 1;
    foru (i , 1 , n)	tmp1 = (tmp1 * fact[cnt[0][i]]) % MOD;
    foru (i , 1 , n)	tmp2 = (tmp2 * fact[cnt[1][i]]) % MOD;
    sort(a + 1 , a + 1 + n);
    res = (res - tmp1 + MOD) % MOD;
    res = (res - tmp2 + MOD) % MOD; 
    int count = 1 , tmp = 1;
    sort(a + 1 , a + 1 + n);
    foru (i , 2 , n)
	{
		if (a[i].fi >= a[i-1].fi && a[i].se >= a[i-1].se) 
		{
			if (a[i].fi == a[i-1].fi && a[i].se == a[i-1].se) 	count++;
			else 
			{
				tmp = (tmp * fact[count]) % MOD;
				count = 1;
			}
			
		} 
		else 
		{
			tmp = 0;
			break;
		}
	}
	tmp = (tmp * fact[count]) % MOD;
    cout << (res + tmp) % MOD;
    return 0;
}
