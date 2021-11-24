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
const int oo = 1e18;
const int MAXN = 1e5 + 1;
int n , sumNegative , res = oo;
int a[MAXN];
int numPositive;
int positive[MAXN] , sum[MAXN];
void solve()
{
    numPositive = 0;
    sumNegative = 0;
    foru (i , 1 , n)
    {
		if (a[i] > 0) positive[++numPositive] = a[i];
		else sumNegative += a[i];
	}
	sort(positive + 1 , positive + 1 + numPositive);
	foru (i , 1 , numPositive)  sum[i] = sum[i-1] + positive[i];
	foru (i , 0 , numPositive)
	{
		int tmp = (numPositive - i) / 2;
		int sumToP = (sum[numPositive] - sum[numPositive-tmp]) - (sum[i+tmp] - sum[i]);
		int sumTo0 = sum[i];
		res = min(res , sumToP + sumTo0 - sumNegative);
	}
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("teleport.inp" , "r" , stdin);
    freopen("teleport.out" , "w" , stdout);
    cin >> n;
    foru (i , 1 , n)
    {
        cin >> a[i];
    }
    solve();
    foru (i , 1 , n)    a[i] *= -1;
    solve();
    cout << res;
    return 0;
}
