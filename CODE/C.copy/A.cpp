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
#define int unsigned long long
using namespace std;
const int oo = 1e18;
const int MAXN = 1e6 + 1;
int n , m;
int a[MAXN] , b[MAXN];
int SumA[MAXN] , SumB[MAXN];
int Mul(int x , int y)
{
	if((oo / x) < y)	return oo;
	return x * y;
}
int solve(int x , int y , int *a)
{
	int res = x * y;
	// cout << res << endl;
	foru(i , 1 , y)
	{
		res = min(res , a[i-1] + Mul(x , (y - i + 1)));
	}
	return res;
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("copy.inp" , "r" , stdin);
    freopen("copy.out" , "w" , stdout);
    cin >> n >> m;
    foru(i , 1 , n)	cin >> a[i];
    foru(i , 1 , m)	cin >> b[i];
    sort(a + 1 , a + 1 + n);
    sort(b + 1 , b + 1 + m);
    foru(i , 1 , n)	SumA[i] = SumA[i-1] + a[i];
    foru(i , 1 , m)	SumB[i] = SumB[i-1] + b[i];
    cout << min(solve(SumA[n] , m , SumB) , solve(SumB[m] , n , SumA));
    return 0;
}
