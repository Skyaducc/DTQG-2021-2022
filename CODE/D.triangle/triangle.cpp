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
#define ll long long
using namespace std;
const int oo = 1e9;
const int MAXN = 220798;
const ll MOD = 2147483648;
const ll tmp = 1103515245;
ll l[MAXN], a[MAXN], b[MAXN];
int n , m;
ll s , v;
bool check(ll x , ll y , ll z)
{
	if (x >= y + z) return false;
	if (y >= x + z) return false;
	if (z >= x + y) return false;
	return true;
}
ll mul(ll a, ll b, ll mod) 
{
	a %= mod; 
	b %= mod; 
	ll x = (long double)a * b / mod; 
	ll y = a * b - x * mod; 
	return (y % mod + mod) % mod;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("triangle.inp" , "r" , stdin);
    freopen("triangle.out" , "w" , stdout);
	cin >> n >> m >> s >> v;
	foru (i , 1 , m) cin >> b[i];
	a[1] = s;
	foru (i , 2 , n) a[i] = (mul(a[i - 1] , tmp , MOD) + 12345) % MOD;
	foru (i , 1 , n)
		if (i <= m) l[i] = b[i];
		else l[i] = 2 * (a[i] % v) - v + 1;
	int res = 0;
	foru (i , 1 , n - 2)
		foru (j , i + 1 , n - 1)
			foru (k , j + 1 , n)
				if (check(l[i] + l[j] , l[j] + l[k] , l[k] + l[i])) res++;
	cout << res;
    return 0;
}
