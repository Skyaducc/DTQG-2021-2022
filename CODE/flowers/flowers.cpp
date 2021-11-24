#include <iostream>
#include <bits/stdc++.h>
#define fi first
#define se second
#define pii pair<int,int>
#define endl '\n'
#define foru(i , a , b) for (int i=a ; i<=b ; i++)
#define ford(i , a , b) for (int i=b ; i>=a ; i--)
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define SET_ON(x, i) ((x) | MASK(i))
#define SET_OFF(x, i) ((x) & ~MASK(i))
#define reset(arr) memset((arr) , 0 , sizeof(arr))
#define debug(x) cout << x << endl; 
#define int long long
using namespace std;
const int oo = 1e9;
int t , p , n , m , k;
int fact[1000001] , finv[1000001];
int Pow(int a , int b)
{
	if(b == 0)	return 1;
	if(b == 1)	return a;
	int tmp = Pow(a , b / 2);
	if(b % 2 == 0)	return tmp * tmp % p;
	else	return tmp * tmp % p * a % p;
}
void ckn()
{
	fact[0] = finv[0] = 1;
	for (int i=1 ; i<=1000000 ; i++)
	{
		fact[i] = fact[i-1] * i % p;
		finv[i] = Pow(fact[i] , p - 2);
	}
}
int comb(int k , int n)
{
	if(k > n)	return 0;
	return 1LL * (fact[n] * finv[k] % p * finv[n-k] % p) % p;
}
int calc(int m , int k)
{
	return m * Pow(m - 1 , k) % p;
}
void solve()
{
	cin >> n >> m >> k;
	cout << (comb(k , n-1) * calc(m , k)) % p << endl;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("A.INP" , "r" , stdin);
    freopen("A.OUT" , "w" , stdout);
    cin >> t >> p;
    ckn();
    while(t--)
    {
    	solve();
    }
    return 0;
}
